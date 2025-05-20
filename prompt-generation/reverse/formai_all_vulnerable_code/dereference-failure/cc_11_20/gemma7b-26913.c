//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main()
{
    int n, m, i, j, iteration = 0;
    int **grid;
    srand(time(NULL));

    // Create a surrealist 2D grid
    n = rand() % 5 + 3;
    m = rand() % 5 + 3;
    grid = (int**)malloc(n * sizeof(int*) + m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        grid[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Percolation simulation
    while (iteration++ < MAX_ITERATIONS)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the four neighbors
                    if (grid[i-1][j] == 1 && grid[i+1][j] == 1 && grid[i][j-1] == 1 && grid[i][j+1] == 1)
                    {
                        grid[i][j] = 2;
                    }
                }
            }
        }
    }

    // Print the final grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}