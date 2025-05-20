//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10

int main()
{
    int **grid = NULL;
    int i, j, k, seed, percolates = 0;
    time_t t;

    seed = time(NULL);
    srand(seed);

    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    t = time(NULL);
    for (k = 0; k < 1000; k++)
    {
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 1)
                {
                    int r = rand() % 4;
                    switch (r)
                    {
                        case 0:
                            if (grid[i - 1][j] == 0)
                                grid[i - 1][j] = 1;
                            break;
                        case 1:
                            if (grid[i + 1][j] == 0)
                                grid[i + 1][j] = 1;
                            break;
                        case 2:
                            if (grid[i][j - 1] == 0)
                                grid[i][j - 1] = 1;
                            break;
                        case 3:
                            if (grid[i][j + 1] == 0)
                                grid[i][j + 1] = 1;
                            break;
                    }
                }
            }
        }
    }

    t = time(NULL) - t;
    printf("Time taken: %ld seconds\n", t);

    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}