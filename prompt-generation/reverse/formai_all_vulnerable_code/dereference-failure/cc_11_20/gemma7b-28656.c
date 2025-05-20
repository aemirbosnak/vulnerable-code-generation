//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

int main()
{
    int **grid = NULL;
    int i, j, k, x, y, z;
    int seed = time(NULL);
    srand(seed);

    grid = (int **)malloc(DIM * sizeof(int *));
    for(i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    for(k = 0; k < 1000; k++)
    {
        x = rand() % DIM;
        y = rand() % DIM;

        if(grid[x][y] == 0)
        {
            grid[x][y] = 1;

            // Spread water to neighboring cells
            for(z = -1; z <= 1; z++)
            {
                if(x + z >= 0 && x + z < DIM && grid[x + z][y] == 0)
                {
                    grid[x + z][y] = 1;
                }
            }

            for(z = -1; z <= 1; z++)
            {
                if(y + z >= 0 && y + z < DIM && grid[x][y + z] == 0)
                {
                    grid[x][y + z] = 1;
                }
            }
        }
    }

    // Print the grid
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}