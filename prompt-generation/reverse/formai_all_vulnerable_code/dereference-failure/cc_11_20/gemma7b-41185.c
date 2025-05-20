//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdlib.h>
#include <time.h>

#define DIM 20
#define MAX_ITERS 1000

int main()
{
    int **grid = NULL;
    int i, j, iter, x, y;

    // Allocate memory for the grid
    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Randomly fill the grid
    srand(time(NULL));
    for (iter = 0; iter < MAX_ITERS; iter++)
    {
        x = rand() % DIM;
        y = rand() % DIM;
        grid[x][y] = 1;
    }

    // Percolation
    for (iter = 0; iter < MAX_ITERS; iter++)
    {
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the neighbors
                    if (grid[i-1][j] == 1)
                        grid[i-1][j] = 1;
                    if (grid[i+1][j] == 1)
                        grid[i+1][j] = 1;
                    if (grid[i][j-1] == 1)
                        grid[i][j-1] = 1;
                    if (grid[i][j+1] == 1)
                        grid[i][j+1] = 1;
                }
            }
        }
    }

    // Print the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}