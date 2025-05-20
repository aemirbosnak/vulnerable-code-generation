//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdlib.h>
#include <stdio.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **grid = NULL;
    int i, j, r, c, seed, percolates = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(ROWS * sizeof(int *));
    for (r = 0; r < ROWS; r++)
    {
        grid[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the grid
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Set the seed
    seed = 123;

    // Percolate the grid
    for (i = 0; i < 1000; i++)
    {
        r = rand() % ROWS;
        c = rand() % COLS;

        if (grid[r][c] == 0)
        {
            grid[r][c] = 1;

            // Check if the cell percolates
            if (percolates == 0)
            {
                for (j = 0; j < ROWS; j++)
                {
                    for (int k = 0; k < COLS; k++)
                    {
                        if (grid[j][k] == 1 && j != r && k != c)
                        {
                            grid[j][k] = 1;
                        }
                    }
                }

                percolates = 1;
            }
        }
    }

    // Print the grid
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (r = 0; r < ROWS; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}