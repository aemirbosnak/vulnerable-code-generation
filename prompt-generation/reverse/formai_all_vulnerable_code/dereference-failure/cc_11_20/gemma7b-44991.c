//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdlib.h>
#include <stdio.h>

#define DIM 10

#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, k, iteration = 0;

    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    grid[5][5] = 1;

    while (iteration < MAX_ITERATIONS)
    {
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (k = -1; k <= 1; k++)
                    {
                        if (i + k >= 0 && i + k < DIM && grid[i + k][j] == 0)
                        {
                            grid[i + k][j] = 1;
                        }
                    }
                    for (k = -1; k <= 1; k++)
                    {
                        if (j + k >= 0 && j + k < DIM && grid[i][j + k] == 0)
                        {
                            grid[i][j + k] = 1;
                        }
                    }
                }
            }
        }
        iteration++;
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}