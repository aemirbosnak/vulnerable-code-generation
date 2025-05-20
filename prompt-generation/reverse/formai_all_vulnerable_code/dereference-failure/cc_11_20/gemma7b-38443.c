//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CELL_SIZE 20
#define POP_SIZE 100
#define MAX_GENERATIONS 10

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Create a cellular automaton
    int **grid = (int**)malloc(CELL_SIZE * sizeof(int*));
    for (int i = 0; i < CELL_SIZE; i++)
    {
        grid[i] = (int*)malloc(CELL_SIZE * sizeof(int));
        for (int j = 0; j < CELL_SIZE; j++)
        {
            grid[i][j] = rand() % POP_SIZE;
        }
    }

    // Simulate generations
    for (int g = 0; g < MAX_GENERATIONS; g++)
    {
        // Calculate the next generation
        int **next_grid = (int**)malloc(CELL_SIZE * sizeof(int*));
        for (int i = 0; i < CELL_SIZE; i++)
        {
            next_grid[i] = (int*)malloc(CELL_SIZE * sizeof(int));
            for (int j = 0; j < CELL_SIZE; j++)
            {
                int neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (grid[r][c] && grid[r][c] != grid[i][j])
                        {
                            neighbors++;
                        }
                    }
                }
                next_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }

        // Copy the next generation to the current generation
        for (int i = 0; i < CELL_SIZE; i++)
        {
            for (int j = 0; j < CELL_SIZE; j++)
            {
                grid[i][j] = next_grid[i][j];
            }
        }

        // Free the memory used for the next generation
        for (int i = 0; i < CELL_SIZE; i++)
        {
            free(next_grid[i]);
        }
        free(next_grid);
    }

    // Print the final grid
    for (int i = 0; i < CELL_SIZE; i++)
    {
        for (int j = 0; j < CELL_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory used for the grid
    for (int i = 0; i < CELL_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}