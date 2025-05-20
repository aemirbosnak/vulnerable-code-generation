//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y;
    time_t t;

    // Allocate memory for the grid
    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (y = 0; y < HEIGHT; y++)
    {
        grid[y] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            grid[y][x] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create some random live cells
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            if (rand() % 10 == 0)
            {
                grid[y][x] = 1;
            }
        }
    }

    // Game loop
    t = time(NULL);
    while (time(NULL) - t < 10)
    {
        // Calculate the number of live neighbors for each cell
        for (y = 0; y < HEIGHT; y++)
        {
            for (x = 0; x < WIDTH; x++)
            {
                int neighbors = 0;
                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        if (grid[y + dy][x + dx] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the Game of Life rules
                if (grid[y][x] == 1 && neighbors < 2)
                {
                    grid[y][x] = 0;
                }
                else if (grid[y][x] == 0 && neighbors == 3)
                {
                    grid[y][x] = 1;
                }
            }
        }

        // Update the grid
        for (y = 0; y < HEIGHT; y++)
        {
            for (x = 0; x < WIDTH; x++)
            {
                printf("%d ", grid[y][x]);
            }
            printf("\n");
        }

        // Sleep for a while
        sleep(1);
    }

    // Free the memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(grid[y]);
    }
    free(grid);

    return 0;
}