//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 50

int main()
{
    int **grid = NULL;
    int i, j, percolates = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == 0)
            {
                percolates++;
                grid[i][j] = 1;
                // Simulate spreading of water
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 1;
                }
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 1;
                }
            }
        }
    }

    // Count the number of percolations
    percolates = 0;
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == 1)
            {
                percolates++;
            }
        }
    }

    // Print the number of percolations
    printf("Number of percolations: %d\n", percolates);

    // Free memory
    for (i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}