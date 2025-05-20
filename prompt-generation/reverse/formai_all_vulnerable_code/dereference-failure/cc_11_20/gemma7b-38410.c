//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdlib.h>
#include <time.h>

#define DIM 20

#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, k;
    int iterations = 0;
    srand(time(NULL));

    grid = (int**)malloc(DIM * sizeof(int*));
    for(i = 0; i < DIM; i++)
    {
        grid[i] = (int*)malloc(DIM * sizeof(int));
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    while(iterations < MAX_ITERATIONS)
    {
        for(i = 0; i < DIM; i++)
        {
            for(j = 0; j < DIM; j++)
            {
                if(grid[i][j] == 1)
                {
                    // Check if the cell is surrounded by water
                    int count = 0;
                    for(k = -1; k <= 1; k++)
                    {
                        if(grid[i + k][j] == 1)
                        {
                            count++;
                        }
                    }
                    for(k = -1; k <= 1; k++)
                    {
                        if(grid[i][j + k] == 1)
                        {
                            count++;
                        }
                    }
                    if(count >= 2)
                    {
                        grid[i][j] = 2;
                    }
                }
            }
        }
        iterations++;
    }

    // Print the final grid
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}