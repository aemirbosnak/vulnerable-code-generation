//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int **percolation_map = NULL;
    int size = MAX_SIZE;
    int i, j, k, iteration = 0;

    // Allocate memory for the grid and percolation map
    grid = (int **)malloc(size * sizeof(int *));
    percolation_map = (int **)malloc(size * sizeof(int *));

    // Initialize the grid and percolation map
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
        percolation_map[i] = (int *)malloc(size * sizeof(int));

        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
            percolation_map[i][j] = 0;
        }
    }

    // Simulate percolation
    while (!percolation_map[size - 1][size - 1] && iteration < MAX_SIZE)
    {
        iteration++;

        // Randomly select a cell
        i = rand() % size;
        j = rand() % size;

        // If the cell is not saturated and the percolation map is not full
        if (grid[i][j] == 0 && percolation_map[i][j] == 0)
        {
            // Saturate the cell
            grid[i][j] = 1;

            // Mark the cell as saturated in the percolation map
            percolation_map[i][j] = 1;

            // Check the four neighboring cells
            for (k = -1; k <= 1; k++)
            {
                if (i + k >= 0 && i + k < size && percolation_map[i + k][j] == 0)
                {
                    percolation_map[i + k][j] = 1;
                }
            }
            for (k = -1; k <= 1; k++)
            {
                if (j + k >= 0 && j + k < size && percolation_map[i][j + k] == 0)
                {
                    percolation_map[i][j + k] = 1;
                }
            }
        }
    }

    // Print the final grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < size; i++)
    {
        free(grid[i]);
        free(percolation_map[i]);
    }
    free(grid);
    free(percolation_map);

    return 0;
}