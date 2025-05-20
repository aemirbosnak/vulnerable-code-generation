//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_GENERATIONS 100

#define EMPTY 0
#define FULL 1

int main()
{
    int **grid = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        grid[i] = malloc(WIDTH * sizeof(int));
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            grid[y][x] = EMPTY;
        }
    }

    grid[10][10] = FULL;
    grid[10][11] = FULL;
    grid[10][12] = FULL;
    grid[11][10] = FULL;
    grid[11][11] = FULL;

    int generations = 0;
    while (generations < MAX_GENERATIONS)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                int neighbors = 0;
                if (grid[y - 1][x] == FULL) neighbors++;
                if (grid[y + 1][x] == FULL) neighbors++;
                if (grid[y][x - 1] == FULL) neighbors++;
                if (grid[y][x + 1] == FULL) neighbors++;

                if (neighbors > 0)
                {
                    grid[y][x] = FULL;
                }
            }
        }

        generations++;
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%d ", grid[y][x]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}