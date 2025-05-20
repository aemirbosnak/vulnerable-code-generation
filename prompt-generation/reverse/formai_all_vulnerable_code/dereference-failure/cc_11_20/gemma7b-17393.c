//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

void draw_grid(int **grid)
{
    for (int r = 0; r < GRID_SIZE; ++r)
    {
        for (int c = 0; c < GRID_SIZE; ++c)
        {
            printf("%c ", grid[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int r = 0; r < GRID_SIZE; ++r)
    {
        grid[r] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Seed the grid with random values
    for (int r = 0; r < GRID_SIZE; ++r)
    {
        for (int c = 0; c < GRID_SIZE; ++c)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Draw the initial grid
    draw_grid(grid);

    // Simulate Game of Life for 10 generations
    for (int gen = 0; gen < 10; ++gen)
    {
        // Calculate the next generation of cells
        int **next_grid = (int **)malloc(GRID_SIZE * sizeof(int *));
        for (int r = 0; r < GRID_SIZE; ++r)
        {
            next_grid[r] = (int *)malloc(GRID_SIZE * sizeof(int));
        }

        for (int r = 0; r < GRID_SIZE; ++r)
        {
            for (int c = 0; c < GRID_SIZE; ++c)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; ++dr)
                {
                    for (int dc = -1; dc <= 1; ++dc)
                    {
                        if (r + dr >= 0 && r + dr < GRID_SIZE && c + dc >= 0 && c + dc < GRID_SIZE && grid[r + dr][c + dc])
                        {
                            neighbors++;
                        }
                    }
                }

                next_grid[r][c] = (neighbors == 3) || (neighbors == 2 && grid[r][c] == 1);
            }
        }

        // Draw the next generation of cells
        draw_grid(next_grid);

        // Free the memory used for the next generation
        for (int r = 0; r < GRID_SIZE; ++r)
        {
            free(next_grid[r]);
        }
        free(next_grid);
    }

    // Free the memory used for the grid
    for (int r = 0; r < GRID_SIZE; ++r)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}