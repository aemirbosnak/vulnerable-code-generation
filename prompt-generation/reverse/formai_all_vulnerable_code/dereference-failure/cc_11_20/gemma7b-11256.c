//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main()
{
    int **board = NULL;
    int i, j, k, l, generation = 0;

    board = malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board with random values
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Game loop
    while (1)
    {
        generation++;

        // Calculate the next generation
        for (k = 0; k < MAX_SIZE; k++)
        {
            for (l = 0; l < MAX_SIZE; l++)
            {
                int neighbors = 0;
                for (i = -1; i <= 1; i++)
                {
                    for (j = -1; j <= 1; j++)
                    {
                        if (board[k + i][l + j] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[k][l] == 1 && neighbors < 2)
                {
                    board[k][l] = 0;
                }
                else if (board[k][l] == 0 && neighbors == 3)
                {
                    board[k][l] = 1;
                }
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

        // Check if the game is over
        if (generation > 10)
        {
            break;
        }
    }

    // Free the memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}