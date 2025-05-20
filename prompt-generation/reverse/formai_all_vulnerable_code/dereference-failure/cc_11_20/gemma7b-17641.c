//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main()
{
    int **grid = NULL;
    int i, j, k;
    int num_percolation = 0;

    grid = (int **)malloc(DIM * sizeof(int *));
    for(i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for(k = 0; k < 100; k++)
    {
        for(i = 0; i < DIM; i++)
        {
            for(j = 0; j < DIM; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(grid[i-1][j] == 1)
                        grid[i][j] = 1;
                    if(grid[i+1][j] == 1)
                        grid[i][j] = 1;
                    if(grid[i][j-1] == 1)
                        grid[i][j] = 1;
                    if(grid[i][j+1] == 1)
                        grid[i][j] = 1;
                }
            }
        }
        num_percolation++;
    }

    printf("Number of percolation: %d\n", num_percolation);

    for(i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}