//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **board = NULL;
    int i, j, k, l, r, c, alive = 0;

    board = malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        board[i] = malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    board[4][5] = 1;
    board[5][5] = 1;
    board[5][6] = 1;

    // Game loop
    while (1)
    {
        for (k = 0; k < MAX; k++)
        {
            for (l = 0; l < MAX; l++)
            {
                alive = 0;
                for (r = -1; r <= 1; r++)
                {
                    for (c = -1; c <= 1; c++)
                    {
                        if (board[k + r][l + c] == 1)
                        {
                            alive++;
                        }
                    }
                }

                if (board[k][l] == 1 && alive < 2)
                {
                    board[k][l] = 0;
                }
                else if (board[k][l] == 0 && alive == 3)
                {
                    board[k][l] = 1;
                }
            }
        }

        // Display the board
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Pause
        system("pause");
    }

    return 0;
}