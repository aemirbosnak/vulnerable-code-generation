//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main()
{
    int **grid = NULL;
    int **percolation_array = NULL;
    int num_sites = DIM * DIM;
    int num_percolation_sites = 0;
    int i, j, k, l, r;
    int seed = time(NULL);

    grid = (int **)malloc(num_sites * sizeof(int *));
    percolation_array = (int **)malloc(num_sites * sizeof(int *));

    for(i = 0; i < num_sites; i++)
    {
        grid[i] = (int *)malloc(sizeof(int) * DIM);
        percolation_array[i] = (int *)malloc(sizeof(int) * DIM);
    }

    for(i = 0; i < num_sites; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
            percolation_array[i][j] = 0;
        }
    }

    srand(seed);

    for(i = 0; i < num_percolation_sites; i++)
    {
        k = rand() % num_sites;
        l = rand() % DIM;
        grid[k][l] = 1;
    }

    for(i = 0; i < num_sites; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            if(grid[i][j] == 1)
            {
                percolation_array[i][j] = 1;
            }
            else
            {
                r = 0;
                for(k = -1; k <= 1; k++)
                {
                    for(l = -1; l <= 1; l++)
                    {
                        if(grid[i + k][j + l] == 1)
                        {
                            r = 1;
                        }
                    }
                }
                if(r == 0)
                {
                    percolation_array[i][j] = 0;
                }
            }
        }
    }

    for(i = 0; i < num_sites; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", percolation_array[i][j]);
        }
        printf("\n");
    }

    free(grid);
    free(percolation_array);

    return 0;
}