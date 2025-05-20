//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

#define EMPTY 0
#define FULL 1

int main()
{
    int **grid = NULL;
    int i, j, x, y, water_level = 0, seeds_planted = 0;

    grid = (int**)malloc(WIDTH * sizeof(int*));
    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = EMPTY;
        }
    }

    // Plant seeds
    x = rand() % WIDTH;
    y = rand() % HEIGHT;
    grid[x][y] = FULL;
    seeds_planted++;

    // Percolation
    while (water_level < HEIGHT && seeds_planted < 10)
    {
        for (i = 0; i < WIDTH; i++)
        {
            for (j = 0; j < HEIGHT; j++)
            {
                if (grid[i][j] == FULL)
                {
                    // Check north
                    if (grid[i][j - 1] == EMPTY && rand() % 2 == 0)
                    {
                        grid[i][j - 1] = FULL;
                        seeds_planted++;
                    }

                    // Check south
                    if (grid[i][j + 1] == EMPTY && rand() % 2 == 0)
                    {
                        grid[i][j + 1] = FULL;
                        seeds_planted++;
                    }

                    // Check east
                    if (grid[i + 1][j] == EMPTY && rand() % 2 == 0)
                    {
                        grid[i + 1][j] = FULL;
                        seeds_planted++;
                    }

                    // Check west
                    if (grid[i - 1][j] == EMPTY && rand() % 2 == 0)
                    {
                        grid[i - 1][j] = FULL;
                        seeds_planted++;
                    }

                    // Water level increases
                    water_level++;
                }
            }
        }
    }

    // Print the grid
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}