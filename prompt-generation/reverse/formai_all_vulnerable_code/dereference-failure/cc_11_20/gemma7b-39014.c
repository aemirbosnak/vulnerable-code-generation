//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define MAX_PERCOLATION 10

int main()
{
    int **grid = NULL;
    int i, j, x, y, water_level = 0, percolate_count = 0;

    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));

    // Randomly fill some cells with water
    for (i = 0; i < MAX_PERCOLATION; i++)
    {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        grid[y][x] = 1;
    }

    // Percolation process
    while (water_level < HEIGHT && percolate_count < MAX_PERCOLATION)
    {
        percolate_count++;

        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check if the cell below is empty and not already filled
                    if (grid[i - 1][j] == 0 && rand() % 2 == 0)
                    {
                        grid[i - 1][j] = 1;
                        water_level++;
                    }
                }
            }
        }
    }

    // Print the final water level
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}