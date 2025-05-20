//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Allocate memory for the grid
    int **grid = (int**)malloc(20 * sizeof(int*));
    for (int i = 0; i < 20; i++)
    {
        grid[i] = (int*)malloc(20 * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Generate the seeds
    int numSeeds = rand() % 10 + 1;
    for (int i = 0; i < numSeeds; i++)
    {
        grid[rand() % 20][rand() % 20] = 1;
    }

    // Percolation
    int x, y, i, j, count = 0;
    for (x = 0; x < 20; x++)
    {
        for (y = 0; y < 20; y++)
        {
            if (grid[x][y] == 1)
            {
                count++;
                grid[x][y] = 2;
                for (i = x - 1; i >= 0 && grid[i][y] == 0; i--)
                {
                    grid[i][y] = 2;
                }
                for (j = y - 1; j >= 0 && grid[x][j] == 0; j--)
                {
                    grid[x][j] = 2;
                }
            }
        }
    }

    // Print the results
    printf("Number of seeds: %d\n", numSeeds);
    printf("Number of droplets: %d\n", count);

    // Free the memory
    for (int i = 0; i < 20; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}