//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 512

int main()
{
    int **grid = NULL;
    int i, j, k, seed, percolate = 0;

    seed = time(NULL);
    srand(seed);

    grid = malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < 1000; k++)
    {
        percolate = 0;
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (i > 0 && grid[i - 1][j] == 1)
                        percolate++;
                    if (j > 0 && grid[i][j - 1] == 1)
                        percolate++;
                    if (i < DIM - 1 && grid[i + 1][j] == 1)
                        percolate++;
                    if (j < DIM - 1 && grid[i][j + 1] == 1)
                        percolate++;
                }
            }
        }

        if (percolate > 0)
        {
            printf("Percolation! (%d iterations)\n", k);
            break;
        }
    }

    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}