//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdlib.h>
#include <time.h>

#define DIM 25

int main()
{
    int **grid = NULL;
    int **percolation = NULL;
    int i, j, r, seed, iterations = 0;

    // Allocate memory
    grid = (int **)malloc(DIM * sizeof(int *));
    percolation = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
        percolation[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the grid and percolation arrays
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
            percolation[i][j] = 0;
        }
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Percolation simulation
    for (iterations = 0; iterations < 10000; iterations++)
    {
        // Randomly choose a cell
        r = rand() % DIM;
        j = rand() % DIM;

        // If the cell is not already saturated and there is a chance of saturation
        if (grid[r][j] == 0 && percolation[r][j] < 50)
        {
            // Saturate the cell
            grid[r][j] = 1;

            // Spread saturation to neighboring cells
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (grid[r + i][j] == 0 && percolation[r + i][j] < 50)
                    {
                        grid[r + i][j] = 1;
                    }
                }
            }
        }
    }

    // Print the percolated grid
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
        for (j = 0; j < DIM; j++)
        {
            free(grid[i][j]);
            free(percolation[i][j]);
        }
        free(grid[i]);
        free(percolation[i]);
    }
    free(grid);
    free(percolation);

    return 0;
}