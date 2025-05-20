//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define ALIVE 1

int main()
{
    int **grid = (int**)malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            grid[i][j] = EMPTY;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create some living cells
    grid[10][10] = ALIVE;
    grid[10][11] = ALIVE;
    grid[11][10] = ALIVE;

    // Game loop
    while (1)
    {
        // Print the grid
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                int aliveCount = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (grid[i + r][j + c] == ALIVE)
                        {
                            aliveCount++;
                        }
                    }
                }

                if (grid[i][j] == ALIVE && aliveCount < 2)
                {
                    grid[i][j] = EMPTY;
                }
                else if (grid[i][j] == EMPTY && aliveCount == 3)
                {
                    grid[i][j] = ALIVE;
                }
            }
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}