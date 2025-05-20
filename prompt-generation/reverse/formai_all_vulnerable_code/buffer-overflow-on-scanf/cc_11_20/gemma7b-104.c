//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

int main()
{
    int sudoku[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int i, j, k, l, m, n;
    char ch;

    printf("Enter the Sudoku puzzle (9x9):\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%c ", &sudoku[i][j]);
        }
    }

    printf("Solving...\n");

    // Invade the sudoku
    for (k = 0; k < MAX; k++)
    {
        for (l = 0; l < MAX; l++)
        {
            if (sudoku[k][l] == 0)
            {
                for (m = 0; m < MAX; m++)
                {
                    for (n = 0; n < MAX; n++)
                    {
                        if (sudoku[m][n] != 0 && (m == k || n == l) && sudoku[m][n] != sudoku[k][l])
                        {
                            sudoku[k][l] = sudoku[m][n];
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("The solution:\n");
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    return 0;
}