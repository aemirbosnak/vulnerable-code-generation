//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int i, j, k, l;

    // Allocate memory for the grid
    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Create a random pattern
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life
    for(k = 0; k < 10; k++)
    {
        for(i = 0; i < MAX_SIZE; i++)
        {
            for(j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                for(l = -1; l <= 1; l++)
                {
                    for(int m = -1; m <= 1; m++)
                    {
                        if(grid[i + l][j + m] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if(grid[i][j] == 1 && neighbors < 2)
                {
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == 0 && neighbors == 3)
                {
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Print the final grid
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}