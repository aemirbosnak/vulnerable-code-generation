//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

int main()
{
    int **grid = NULL;
    int i, j, k, seed, percolates = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++)
    {
        grid[i] = (int *)malloc(N * sizeof(int));
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Generate the grid
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Check if the grid percolates
    for (k = 0; k < N; k++)
    {
        if (grid[0][k] == 1 && grid[N - 1][k] == 1)
        {
            percolates = 1;
        }
    }

    // Print the grid
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Print whether the grid percolates
    if (percolates)
    {
        printf("The grid percolates.\n");
    }
    else
    {
        printf("The grid does not percolate.\n");
    }

    // Free the memory allocated for the grid
    for (i = 0; i < N; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}