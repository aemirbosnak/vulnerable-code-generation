//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int x, y, i, j, k, l, alive_cells = 0;

    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (x = 0; x < MAX_SIZE; x++)
    {
        grid[x] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < MAX_SIZE; x++)
    {
        for (y = 0; y < MAX_SIZE; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Create a random pattern
    for (i = 0; i < 10; i++)
    {
        x = rand() % MAX_SIZE;
        y = rand() % MAX_SIZE;
        grid[x][y] = 1;
    }

    // Simulate Game of Life
    for (k = 0; k < 5; k++)
    {
        for (l = 0; l < MAX_SIZE; l++)
        {
            for (i = 0; i < MAX_SIZE; i++)
            {
                for (j = 0; j < MAX_SIZE; j++)
                {
                    int neighbors = 0;
                    if (i > 0) neighbors++;
                    if (i < MAX_SIZE - 1) neighbors++;
                    if (j > 0) neighbors++;
                    if (j < MAX_SIZE - 1) neighbors++;

                    if (grid[i][j] == 1 && neighbors < 2)
                        grid[i][j] = 0;
                    else if (grid[i][j] == 0 && neighbors == 3)
                        grid[i][j] = 1;
                }
            }
        }

        // Print the grid
        for (x = 0; x < MAX_SIZE; x++)
        {
            for (y = 0; y < MAX_SIZE; y++)
            {
                printf("%d ", grid[x][y]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (x = 0; x < MAX_SIZE; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}