//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 10
#define NUM_GENERATIONS 10

int main()
{
    int **grid = NULL;
    int i, j, g, r, c;

    // Allocate memory for the grid
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for(i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create the initial generations
    for(g = 0; g < NUM_GENERATIONS; g++)
    {
        for(i = 0; i < GRID_SIZE; i++)
        {
            for(j = 0; j < GRID_SIZE; j++)
            {
                r = rand() % 2;
                if(r == 0)
                {
                    grid[i][j] = 1;
                }
            }
        }
    }

    // Print the final generation
    for(i = 0; i < GRID_SIZE; i++)
    {
        for(j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}