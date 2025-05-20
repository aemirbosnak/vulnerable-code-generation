//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

#define MAX_SIM 1000

int main()
{
    int **grid = NULL;
    int i, j, k, sim_num = 0, per_chance = 50;

    grid = malloc(DIM * sizeof(int *));
    for(i = 0; i < DIM; i++)
    {
        grid[i] = malloc(DIM * sizeof(int));
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));

    for(sim_num = 0; sim_num < MAX_SIM; sim_num++)
    {
        for(i = 0; i < DIM; i++)
        {
            for(j = 0; j < DIM; j++)
            {
                if(grid[i][j] == 0 && rand() % per_chance == 0)
                {
                    grid[i][j] = 1;
                }
            }
        }

        for(k = 0; k < DIM; k++)
        {
            for(i = 0; i < DIM; i++)
            {
                if(grid[i][k] == 1 && grid[k][i] == 1)
                {
                    grid[i][k] = 2;
                }
            }
        }
    }

    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}