//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **board = NULL;
    int x, y, i, j, k, l, r, s, t;

    // Allocate memory for the board
    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set the initial state of the board
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate life
    while (1)
    {
        // Calculate the number of neighbors for each cell
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                k = 0;
                l = -1;
                r = 1;
                s = -1;
                t = 1;

                while (l++ < r)
                {
                    if (board[i - l][j] == 1)
                        k++;
                }

                while (s++ < t)
                {
                    if (board[i][j - s] == 1)
                        k++;
                }

                if (board[i][j] == 1 && k < 2)
                    board[i][j] = 0;
                else if (board[i][j] == 0 && k == 3)
                    board[i][j] = 1;
            }
        }

        // Print the board
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
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