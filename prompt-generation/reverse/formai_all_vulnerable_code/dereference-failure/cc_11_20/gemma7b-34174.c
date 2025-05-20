//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int i, j, k, l, size = MAX_SIZE;
    int generation = 0;
    srand(time(NULL));

    // Allocate memory for the grid
    grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Game loop
    while (1)
    {
        // Calculate the next generation
        for (k = 0; k < size; k++)
        {
            for (l = 0; l < size; l++)
            {
                int neighbors = 0;
                for (i = -1; i <= 1; i++)
                {
                    for (j = -1; j <= 1; j++)
                    {
                        if (grid[k + i][l + j] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (grid[k][l] == 1 && neighbors < 2)
                {
                    grid[k][l] = 0;
                }
                else if (grid[k][l] == 0 && neighbors == 3)
                {
                    grid[k][l] = 1;
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

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation == 10)
        {
            break;
        }
    }

    // Free memory
    for (i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}