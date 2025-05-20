//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int **next_grid = NULL;
    int size = 0;
    int i, j, k, l, m, n;

    printf("Enter the size of the grid: ");
    scanf("%d", &size);

    grid = (int **)malloc(size * sizeof(int *));
    next_grid = (int **)malloc(size * sizeof(int *));

    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
        next_grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
            next_grid[i][j] = 0;
        }
    }

    // Play the game
    while (1)
    {
        // Get the next generation
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                n = 0;
                for (k = -1; k <= 1; k++)
                {
                    for (l = -1; l <= 1; l++)
                    {
                        if (k == 0 && l == 0)
                            continue;
                        if (grid[i + k][j + l] == 1)
                            n++;
                    }
                }
                next_grid[i][j] = (n == 2) || (n == 3);
            }
        }

        // Copy the next generation to the grid
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                grid[i][j] = next_grid[i][j];
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

        // Check if the game is over
        if (grid[size - 1][size - 1] == 1)
            break;
    }

    // Free the memory
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            free(grid[i][j]);
            free(next_grid[i][j]);
        }
        free(grid[i]);
        free(next_grid[i]);
    }
    free(grid);
    free(next_grid);

    return 0;
}