//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define a 2D array of integers to store the state of the grid
    int **grid = NULL;

    // Allocate memory for the grid
    grid = malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        grid[i] = malloc(10 * sizeof(int));
    }

    // Initialize the grid with random values
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Percolation algorithm
    for (int iter = 0; iter < 1000; iter++)
    {
        // Iterate over the grid
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // If the cell is wet and the neighboring cells are dry, make it wet
                if (grid[i][j] == 1 && (grid[i-1][j] == 0 || grid[i+1][j] == 0 || grid[i][j-1] == 0 || grid[i][j+1] == 0))
                {
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < 10; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}