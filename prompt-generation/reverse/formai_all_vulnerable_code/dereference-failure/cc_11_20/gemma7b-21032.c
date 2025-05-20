//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void drawGrid(int **grid, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", grid[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 10;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        grid[r] = (int *)malloc(size * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Draw the grid
    drawGrid(grid, size);

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        drawGrid(grid, size);

        // Calculate the next generation
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (r + dr >= 0 && r + dr < size && c + dc >= 0 && c + dc < size && grid[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (grid[r][c] == 1 && neighbors < 2)
                {
                    grid[r][c] = 0;
                }
                else if (grid[r][c] == 0 && neighbors == 3)
                {
                    grid[r][c] = 1;
                }
            }
        }
    }

    // Draw the final grid
    drawGrid(grid, size);

    // Free the memory
    for (int r = 0; r < size; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}