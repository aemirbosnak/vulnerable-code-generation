//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10

#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, k, iterations = 0;
    srand(time(NULL));

    grid = (int**)malloc(DIM * sizeof(int*));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int*)malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation Simulation
    for (k = 0; k < MAX_ITERATIONS; k++)
    {
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the four neighbors
                    if (grid[i - 1][j] == 0 && rand() % 2 == 0)
                        grid[i - 1][j] = 1;
                    if (grid[i + 1][j] == 0 && rand() % 2 == 0)
                        grid[i + 1][j] = 1;
                    if (grid[i][j - 1] == 0 && rand() % 2 == 0)
                        grid[i][j - 1] = 1;
                    if (grid[i][j + 1] == 0 && rand() % 2 == 0)
                        grid[i][j + 1] = 1;
                }
            }
        }
        iterations++;
    }

    // Print the final grid
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