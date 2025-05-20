//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main()
{
    int **grid = NULL;
    int i, j, k, p, q;
    time_t t;

    // Allocate memory for the grid
    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolations
    t = time(NULL);
    for (k = 0; k < 100000; k++)
    {
        p = rand() % DIM;
        q = rand() % DIM;

        if (grid[p][q] == 0)
        {
            grid[p][q] = 1;

            // Percolate vertically
            for (i = p - 1; i >= 0 && grid[i][q] == 0; i--)
            {
                grid[i][q] = 1;
            }

            // Percolate horizontally
            for (j = q - 1; j >= 0 && grid[p][j] == 0; j--)
            {
                grid[p][j] = 1;
            }
        }
    }

    // Print the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}