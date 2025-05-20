//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GENERATIONS 200
#define GRID_SIZE 20

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the game grid
    int grid[GRID_SIZE][GRID_SIZE] = {{0}};

    // Initialize the game state
    for (int g = 0; g < MAX_GENERATIONS; g++)
    {
        // Simulate the game
        for (int r = 0; r < GRID_SIZE; r++)
        {
            for (int c = 0; c < GRID_SIZE; c++)
            {
                int neighbors = 0;
                // Count the number of neighbors
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (grid[r + dr][c + dc] && grid[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the Game of Life rules
                if (grid[r][c] == 0 && neighbors == 3)
                {
                    grid[r][c] = 1;
                }
                else if (grid[r][c] == 1 && (neighbors < 2 || neighbors > 3))
                {
                    grid[r][c] = 0;
                }
            }
        }

        // Print the game grid
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