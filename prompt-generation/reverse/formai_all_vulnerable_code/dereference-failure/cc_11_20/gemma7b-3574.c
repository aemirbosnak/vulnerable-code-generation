//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 100

int main()
{
    int** grid = NULL;
    int size = MAX_PERCOLATION_SIZE;
    int i, j, k, l, r, c, seed;
    int water_amount = 0;

    // Allocate memory for the grid
    grid = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++)
    {
        grid[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Fill the grid with water
    for (k = 0; k < water_amount; k++)
    {
        r = rand() % size;
        c = rand() % size;
        grid[r][c] = 1;
    }

    // Percolate the water
    for (l = 0; l < MAX_PERCOLATION_SIZE; l++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check the four neighbors
                    if (grid[i-1][j] == 0 && rand() % 2 == 0)
                        grid[i-1][j] = 1;
                    if (grid[i+1][j] == 0 && rand() % 2 == 0)
                        grid[i+1][j] = 1;
                    if (grid[i][j-1] == 0 && rand() % 2 == 0)
                        grid[i][j-1] = 1;
                    if (grid[i][j+1] == 0 && rand() % 2 == 0)
                        grid[i][j+1] = 1;
                }
            }
        }
    }

    // Print the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}