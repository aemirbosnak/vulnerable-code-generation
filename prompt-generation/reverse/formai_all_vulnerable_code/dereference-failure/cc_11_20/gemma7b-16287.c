//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **board = NULL;
    int i, j, k, l;

    // Allocate memory for the game board
    board = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the game board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place the initial seeds
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Game loop
    while (1)
    {
        // Calculate the next generation
        for (k = 0; k < MAX; k++)
        {
            for (l = 0; l < MAX; l++)
            {
                int neighbors = 0;
                if (board[k][l] == 1)
                {
                    neighbors++;
                }
                if (board[k][l] == 0 && neighbors == 3)
                {
                    board[k][l] = 1;
                }
                else if (board[k][l] == 1 && neighbors < 2)
                {
                    board[k][l] = 0;
                }
            }
        }

        // Print the game board
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (board[0][0] == 1 && board[MAX - 1][MAX - 1] == 1)
        {
            break;
        }

        // Pause the game
        sleep(1);
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}