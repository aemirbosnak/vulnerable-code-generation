//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
// Game of Life Cellular Automata Simulator in Ada Lovelace Style

#include <stdio.h>
#include <stdlib.h>

#define DIM 20

int main()
{
    // Allocate memory for the grid
    int **grid = malloc(DIM * sizeof(int *));
    for (int i = 0; i < DIM; i++)
    {
        grid[i] = malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the grid with life
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[6][5] = 1;
    grid[6][6] = 1;

    // Simulate generations
    int gen = 0;
    while (gen < 10)
    {
        // Calculate the next generation
        for (int i = 0; i < DIM; i++)
        {
            for (int j = 0; j < DIM; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0) continue;
                        if (grid[i + x][j + y] == 1) neighbors++;
                    }
                }

                if (neighbors < 2) grid[i][j] = 0;
                else if (neighbors == 2) grid[i][j] = 1;
            }
        }

        // Print the grid
        for (int i = 0; i < DIM; i++)
        {
            for (int j = 0; j < DIM; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        gen++;
    }

    // Free memory
    for (int i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}