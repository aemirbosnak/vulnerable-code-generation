//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int size = MAX_SIZE;
    int **grid = malloc(size * sizeof(int *)), **ngrid = malloc(size * sizeof(int *)), tmpGrid = NULL;

    // Initialize the grid
    for (int i = 0; i < size; i++)
    {
        grid[i] = malloc(size * sizeof(int));
        ngrid[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
            ngrid[i][j] = 0;
        }
    }

    // Create the game logic
    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int neighbors = 0;
                if (i > 0) neighbors++;
                if (i < size - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < size - 1) neighbors++;

                if (grid[i][j] == 1 && neighbors < 2) ngrid[i][j] = 0;
                if (grid[i][j] == 0 && neighbors == 3) ngrid[i][j] = 1;
            }
        }

        // Copy the new grid to the old grid
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                grid[i][j] = ngrid[i][j];
            }
        }

        // Print the grid
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            free(grid[i][j]);
            free(ngrid[i][j]);
        }
        free(grid[i]);
        free(ngrid[i]);
    }
    free(grid);
    free(ngrid);

    return 0;
}