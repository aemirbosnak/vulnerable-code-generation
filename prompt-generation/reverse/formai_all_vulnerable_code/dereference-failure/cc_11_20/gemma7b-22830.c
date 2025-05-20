//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Print the board
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (board[i + r][j + c] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation > 10)
        {
            break;
        }
    }

    // Free the memory
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}