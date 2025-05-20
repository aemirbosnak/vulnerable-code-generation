//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main()
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        grid[i] = (int *)malloc(10 * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Randomly select sites to be occupied
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;
        grid[x][y] = 1;
    }

    // Percolation algorithm
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (grid[i][j] == 1)
                {
                    int neighbors = 0;
                    if (grid[i-1][j] == 1) neighbors++;
                    if (grid[i+1][j] == 1) neighbors++;
                    if (grid[i][j-1] == 1) neighbors++;
                    if (grid[i][j+1] == 1) neighbors++;

                    if (neighbors >= 2)
                    {
                        grid[i][j] = 2;
                    }
                }
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < 10; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}