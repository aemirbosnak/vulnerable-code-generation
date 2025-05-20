//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int i, j, k, l, alive = 0, dead = 0;

    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Game of Life Rules
    for (k = 0; k < MAX_SIZE; k++)
    {
        for (l = 0; l < MAX_SIZE; l++)
        {
            alive = 0;
            dead = 0;

            // Check Neighbors
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (board[k + i][l + j] == 1)
                    {
                        alive++;
                    }
                }
            }

            // Apply Rules
            if (board[k][l] == 1 && alive < 2)
            {
                dead++;
            }
            else if (board[k][l] == 0 && alive == 3)
            {
                alive++;
            }

            board[k][l] = alive - dead;
        }
    }

    // Print the Results
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}