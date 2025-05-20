//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Game board dimensions
    int rows = 20;
    int cols = 20;

    // Initialize the game board
    int **board = (int *)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Randomly activate some cells
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (rand() % 20 == 0)
            {
                board[r][c] = 1;
            }
        }
    }

    // Simulate the game of life
    for (int generation = 0; generation < 10; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
    }

    // Free the game board memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}