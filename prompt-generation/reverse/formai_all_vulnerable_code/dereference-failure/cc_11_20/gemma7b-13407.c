//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 20

int main()
{
    int **grid = NULL;
    int x, y, i, j, seed, fill, percolate;

    // Allocate memory for the grid
    grid = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        grid[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Fill the grid randomly
    fill = rand() % MAX;
    grid[fill][fill] = 1;

    // Percolate the water
    percolate = 1;
    while (percolate)
    {
        percolate = 0;
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (i - 1 >= 0 && grid[i - 1][j] == 0)
                    {
                        grid[i - 1][j] = 1;
                        percolate = 1;
                    }
                    if (i + 1 < MAX && grid[i + 1][j] == 0)
                    {
                        grid[i + 1][j] = 1;
                        percolate = 1;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 0)
                    {
                        grid[i][j - 1] = 1;
                        percolate = 1;
                    }
                    if (j + 1 < MAX && grid[i][j + 1] == 0)
                    {
                        grid[i][j + 1] = 1;
                        percolate = 1;
                    }
                }
            }
        }
    }

    // Print the grid
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}