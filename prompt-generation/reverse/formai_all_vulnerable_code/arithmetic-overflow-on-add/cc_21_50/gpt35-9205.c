//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, m, carton[5][5], num, quit = 0;
    int lineas[5] = {0, 0, 0, 0, 0}, bingo = 0;
    srand(time(NULL));

    printf("\nBienvenido al Simulador de Bingo!\n\n");

    printf("Ingrese la cantidad de cartones de Bingo que desea generar (1-10): ");
    scanf("%d", &n);

    printf("Ingrese el numero maximo para generar los numeros de Bingo (1-75): ");
    scanf("%d", &m);

    // Generar cartones de Bingo
    for (i = 1; i <= n; i++)
    {
        printf("\nCarton %d:\n", i);

        for (j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (j == 2 && k == 2)
                {
                    carton[j][k] = 0; // Casilla central
                }
                else
                {
                    num = rand() % m + 1;
                    carton[j][k] = num;
                }
            }
        }

        // Imprimir carton
        for (j = 0; j < 5; j++)
        {
            printf("+----+----+----+----+----+\n");
            for (int k = 0; k < 5; k++)
            {
                printf("| ");
                if (carton[j][k] < 10)
                {
                    printf(" ");
                }
                if (carton[j][k] == 0)
                {
                    printf("X");
                }
                else
                {
                    printf("%d", carton[j][k]);
                }
                printf(" ");
            }
            printf("|\n");
        }
        printf("+----+----+----+----+----+\n");
    }

    printf("\nComenzando el juego de Bingo...\n");

    // Inicio del juego de Bingo
    while (!bingo && !quit)
    {
        printf("\nIngrese un numero (1-75) o 0 para salir: ");
        scanf("%d", &num);

        if (num == 0)
        {
            quit = 1;
            break;
        }

        // Buscar y marcar el numero en los cartones
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (carton[j][k] == num)
                    {
                        carton[j][k] = 0;

                        // Verificar lineas y bingo
                        if (j == k)
                        {
                            lineas[i-1]++;
                        }
                        if (j == 4-k)
                        {
                            lineas[i-1]++;
                        }
                        for (int l = 0; l < 5; l++)
                        {
                            if (carton[j][l] != 0 && k == 4 && l == 4)
                            {
                                break;
                            }
                            if (carton[j][l] == 0 && l == 4)
                            {
                                lineas[i-1]++;
                            }
                            if (carton[l][k] != 0 && j == 4 && l == 4)
                            {
                                break;
                            }
                            if (carton[l][k] == 0 && l == 4)
                            {
                                lineas[i-1]++;
                            }
                        }
                        if (lineas[i-1] == 5)
                        {
                            printf("\nLINEA! Carton %d\n", i);
                        }
                        if (carton[0][0] == 0 && carton[0][4] == 0 && carton[4][0] == 0 && carton[4][4] == 0)
                        {
                            bingo = i;
                        }
                    }
                }
            }
        }

        // Imprimir cartones
        for (i = 1; i <= n; i++)
        {
            printf("\nCarton %d:\n", i);
            for (j = 0; j < 5; j++)
            {
                printf("+----+----+----+----+----+\n");
                for (int k = 0; k < 5; k++)
                {
                    printf("| ");
                    if (carton[j][k] < 10)
                    {
                        printf(" ");
                    }
                    if (carton[j][k] == 0)
                    {
                        printf("X");
                    }
                    else
                    {
                        printf("%d", carton[j][k]);
                    }
                    printf(" ");
                }
                printf("|\n");
            }
            printf("+----+----+----+----+----+\n");
        }
    }

    if (bingo)
    {
        printf("\nBINGO! Ganador: Carton %d\n", bingo);
    }
    if (quit)
    {
        printf("\nJuego finalizado.\n");
    }

    return 0;
}