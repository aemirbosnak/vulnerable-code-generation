//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize a 2D array to store the game board
    int **board = NULL;
    board = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = malloc(5 * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the initial board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Display the initial board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int neighbors = 0;
                // Check the cells to the left
                if (j > 0)
                {
                    neighbors++;
                }
                // Check the cells above
                if (i > 0)
                {
                    neighbors++;
                }
                // Check the cells to the right
                if (j < 4)
                {
                    neighbors++;
                }
                // Check the cells below
                if (i < 4)
                {
                    neighbors++;
                }
                // If the cell has 2 or more neighbors, it survives
                if (board[i][j] == 1 && neighbors >= 2)
                {
                    board[i][j] = 1;
                }
                // Otherwise, the cell dies
                else
                {
                    board[i][j] = 0;
                }
            }
        }

        // Display the updated board
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}