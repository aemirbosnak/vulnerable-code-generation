//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define CELL_SIZE 10

int main()
{
    // Initialize the grid
    int **grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(CELL_SIZE * sizeof(int));
        for (int j = 0; j < CELL_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Randomly populate the grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < CELL_SIZE; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Run the game of life
    for (int generation = 0; generation < 10; generation++)
    {
        // Calculate the next generation of cells
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < CELL_SIZE; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                        {
                            continue;
                        }
                        if (grid[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }
                if (neighbors < 2 || neighbors > 3)
                {
                    grid[i][j] = 0;
                }
            }
        }

        // Print the grid
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < CELL_SIZE; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}