//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (int r = 0; r < HEIGHT; r++)
    {
        grid[r] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Simulate life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < HEIGHT; r++)
        {
            for (int c = 0; c < WIDTH; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < HEIGHT - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < WIDTH - 1) neighbors++;

                // Apply the Game of Life rules
                if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
                if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            }
        }

        // Print the grid
        for (int r = 0; r < HEIGHT; r++)
        {
            for (int c = 0; c < WIDTH; c++)
            {
                printf("%d ", grid[r][c]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int r = 0; r < HEIGHT; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}