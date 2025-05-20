//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a grid of cells
    int grid[GRID_SIZE][GRID_SIZE] = {{0}};

    // Initialize the game of life rules
    int neighbor_rules[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    // Simulate the game of life
    for (int t = 0; t < 100; t++)
    {
        // Calculate the next generation of cells
        for (int r = 0; r < GRID_SIZE; r++)
        {
            for (int c = 0; c < GRID_SIZE; c++)
            {
                int num_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (grid[r + dr][c + dc] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                if (grid[r][c] == 1 && num_neighbors < neighbor_rules[t])
                {
                    grid[r][c] = 0;
                }
                else if (grid[r][c] == 0 && num_neighbors == neighbor_rules[t])
                {
                    grid[r][c] = 1;
                }
            }
        }

        // Print the grid
        for (int r = 0; r < GRID_SIZE; r++)
        {
            for (int c = 0; c < GRID_SIZE; c++)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }
    }

    return 0;
}