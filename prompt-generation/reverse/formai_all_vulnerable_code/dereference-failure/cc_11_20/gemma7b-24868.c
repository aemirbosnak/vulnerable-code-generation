//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 512

int main()
{
    int **grid = NULL;
    int i, j, k, seed;

    // Allocate memory for the grid
    grid = (int **)malloc(DIM * sizeof(int *));
    for(i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set the seed for the random number generator
    seed = time(NULL);
    srand(seed);

    // Percolation simulation
    for(k = 0; k < 1000; k++)
    {
        // Randomly choose a cell
        i = rand() % DIM;
        j = rand() % DIM;

        // If the cell is not already saturated and there is a chance of saturation
        if(grid[i][j] == 0 && rand() % 2 == 0)
        {
            // Saturate the cell
            grid[i][j] = 1;

            // Check if the cell is a boundary cell
            if(i == 0 || i == DIM - 1 || j == 0 || j == DIM - 1)
            {
                // Print the cell
                printf("(%d, %d) is saturated\n", i, j);
            }
        }
    }

    // Free the memory allocated for the grid
    for(i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}