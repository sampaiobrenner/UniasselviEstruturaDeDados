#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    // Define as configurações de localização para português
    setlocale(LC_ALL, "Portuguese");

    // Declara as matrizes
    int matricula[50];

    /* Quando se manipula strings (textos) em C deve-se declarar um
       caracter a mais para armazenar o terminador de string '\0' (nulo) */
    char nome[50][61]; // 60 caracteres + '\0' = 61

    float parcial1[50];
    float oficial1[50];
    float parcial2[50];
    float oficial2[50];

    float media[50];

    // Controla a quantidade de elementos cadastrada nos vetores
    int index = 0;

    // Representa a escolha do usuário a partir das opções presentes no menu
    int opcao = 0;

    // Indica a informação solicitada foi encontrada durante uma consulta
    int achou = 0; // [0] Não localizado (false) / [1] Localizado (true)

    do
    {
        // Gera o menu de opções para o usuário
        //system("clear");
        system("cls");
        printf("========= MENU ========= \n");
        printf("1) Cadastrar \n");
        printf("2) Pesquisar (Matricula) \n");
        printf("3) Pesquisar (Nome) \n");
        printf("4) Gerar Médias \n");
        printf("5) Listar Alunos Aprovados \n");
        printf("6) Listar Alunos em Exame \n");
        printf("0) Finalizar \n");
        printf("======================== \n");
        printf("Opção: ");

        // Lê a opção escolhida pelo usuário
        scanf("%d", &opcao);
        fflush(stdin); // Windows
        //__fpurge(stdin); // Linux


        // Trata a opção escolhida pelo usuário
        switch(opcao)
        {
            case 1: // Cadastrar

                // Verifica se ainda podem ser cadastradas novas informações nas matrizes
                if (index < 50)
                {
                    // Limpa o console
                    //system("clear");
                    system("cls");

                    printf("========= Cadastrar ========= \n");
                    printf("Matricula: ");
                    scanf("%d", &matricula[index]);
                    fflush(stdin);
                    //__fpurge(stdin);


                    printf("Nome: ");
                    scanf("%[^\n]", &nome[index]); // "%[^\n]" usado para ler os nomes compostos
                    fflush(stdin);
                    //__fpurge(stdin);

                    printf("Parcial 1: ");
                    scanf("%f", &parcial1[index]);
                    fflush(stdin);
                    //__fpurge(stdin);

                    printf("Oficial 1: ");
                    scanf("%f", &oficial1[index]);
                    fflush(stdin);
                    //__fpurge(stdin);

                    printf("Parcial 2: ");
                    scanf("%f", &parcial2[index]);
                    fflush(stdin);
                    //__fpurge(stdin);

                    printf("Oficial 2: ");
                    scanf("%f", &oficial2[index]);
                    fflush(stdin);
                    //__fpurge(stdin);

                    // Incrementa o controle da quantidade de elementos cadastrados nos vetores
                    index++;

                    printf("Cadastrado com sucesso... \n");
                }
                else
                {
                    printf("Limite de cadastros atingido... \n");
                }

                printf("Pressione qualquer teclar para continuar...");
                getchar(); // Lê a tecla pressionada pelo usuário
                break;

            case 2: // Pesquisar (Matricula)

                //system("clear");
                system("cls");

                // Variável usada para armazenar a matricula a ser pesquisada
                int pesquisarMatricula;

                printf("========= Pesquisar (Matricula) ========= \n");
                printf("Matricula: ");
                scanf("%d", &pesquisarMatricula);
                fflush(stdin);
                //__fpurge(stdin);

                // Define como NÃO localizado
                achou = 0; // false

                for (int i = 0; i < index; i++)
                {
                    if (pesquisarMatricula == matricula[i])
                    {
                        // Define como localizado
                        achou = 1; // true

                        printf("Nome: %s \n", nome[i]);
                        printf("Parcial 1: %.2f \n", parcial1[i]);
                        printf("Oficial 1: %.2f \n", oficial1[i]);
                        printf("Parcial 2: %.2f \n", parcial2[i]);
                        printf("Oficial 2: %.2f \n", oficial2[i]);
                        printf("Média: %.2f \n", media[i]);
                    }
                }

                // Se não localizou, informa o usuário
                if (!achou)
                {
                    printf("Matricula NÃO localizada... \n");
                }

                printf("Pressione qualquer teclar para continuar...");
                getchar();
                break;

            case 3: // Pesquisar (Nome)

                //system("clear");
                system("cls");

                char pesquisarNome[61];

                printf("========= Pesquisar (Nome) ========= \n");
                printf("Nome: ");
                scanf("%[^\n]", &pesquisarNome);
                fflush(stdin);
                //__fpurge(stdin);

                achou = 0;

                for (int i = 0; i < index; i++)
                {
                    // strstr() localiza uma substring em um string
                    if (strstr(nome[i], pesquisarNome) != 0)
                    {
                        achou = 1;

                        printf("Matricula: %d \n", matricula[i]);
                        printf("Parcial 1: %.2f \n", parcial1[i]);
                        printf("Oficial 1: %.2f \n", oficial1[i]);
                        printf("Parcial 2: %.2f \n", parcial2[i]);
                        printf("Oficial 2: %.2f \n", oficial2[i]);
                        printf("Média: %.2f \n", media[i]);
                        printf("\n");
                    }
                }

                if (!achou)
                {
                    printf("Nome NÃO localizado... \n");
                }

                printf("Pressione qualquer teclar para continuar...");
                getchar();
                break;

            case 4: // Gerar Médias

                //system("clear");
                system("cls");

                printf("========= Gerar Médias ========= \n");
                printf("\n"); // Inseri uma linha em branco no console
                printf("Gerando médias... \n");

                for (int i = 0; i < index; i++)
                {
                    media[i] = ((parcial1[i] * 1.2) + (oficial1[i] * 2.8) + (parcial2[i] * 1.8) + (oficial2[i] * 4.2)) / 10;
                }

                printf("Médias geradas com sucesso... \n");
                printf("Pressione qualquer teclar para continuar...");
                getchar();
                break;

            case 5: // Listar Alunos Aprovados

                //system("clear");
                system("cls");

                printf("========= Listar Alunos Aprovados ========= \n");

                for (int i = 0; i < index; i++)
                {
                    if (media[i] >= 7)
                    {
                        printf("Matricula: %d \n", matricula[i]);
                        printf("Nome: %s \n", nome[i]);
                        printf("Parcial 1: %.2f \n", parcial1[i]);
                        printf("Oficial 1: %.2f \n", oficial1[i]);
                        printf("Parcial 2: %.2f \n", parcial2[i]);
                        printf("Oficial 2: %.2f \n", oficial2[i]);
                        printf("Média: %.2f \n", media[i]);
                        printf("\n");
                    }
                }

                printf("Pressione qualquer teclar para continuar...");
                getchar();
                break;

            case 6: // Listar Alunos em Exame

                //system("clear");
                system("cls");

                printf("========= Listar Alunos em Exame ========= \n");

                for (int i = 0; i < index; i++)
                {
                    if (media[i] < 7)
                    {
                        printf("Matricula: %d \n", matricula[i]);
                        printf("Nome: %s \n", nome[i]);
                        printf("Parcial 1: %.2f \n", parcial1[i]);
                        printf("Oficial 1: %.2f \n", oficial1[i]);
                        printf("Parcial 2: %.2f \n", parcial2[i]);
                        printf("Oficial 2: %.2f \n", oficial2[i]);
                        printf("Média: %.2f \n", media[i]);
                        printf("\n");
                    }
                }

                printf("Pressione qualquer teclar para continuar...");
                getchar();
                break;

            case 0: // Finalizar

                //system("clear");
                system("cls");
                printf("Aplicação finalizada... \n");
                break;

            default: // Outros números

                //system("clear");
                system("cls");
                printf("Opção inválida... \n");
                printf("Pressione qualquer teclar para continuar...");
                getchar(); // Aguarda que o usuário pressione qualquer tecla
                break;
        }
    } while (opcao != 0);

    return 0;
}
