//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define MAX_ITERATIONS 1000

int main()
{
    int **grid = NULL;
    int i, j, iteration = 0;
    srand(time(NULL));

    grid = (int **)malloc(WIDTH * sizeof(int *));
    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    while (iteration < MAX_ITERATIONS)
    {
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == 1 && (grid[i-1][j] == 1 || grid[i+1][j] == 1 || grid[i][j-1] == 1 || grid[i][j+1] == 1))
                {
                    grid[i][j] = 2;
                }
            }
        }
        iteration++;
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}