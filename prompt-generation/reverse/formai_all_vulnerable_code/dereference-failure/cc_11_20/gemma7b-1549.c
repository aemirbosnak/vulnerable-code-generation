//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25
#define NUM_SITES 1000

#define PERCOLATION_THRESHOLD 50

int main()
{
    int **grid = (int**)malloc(WIDTH * sizeof(int*));
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    for (int i = 0; i < NUM_SITES; i++)
    {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        grid[x][y] = 1;
    }

    int num_percolation = 0;
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (grid[i][j] == 1)
            {
                int neighbors = 0;
                if (grid[i - 1][j] == 1) neighbors++;
                if (grid[i + 1][j] == 1) neighbors++;
                if (grid[i][j - 1] == 1) neighbors++;
                if (grid[i][j + 1] == 1) neighbors++;

                if (neighbors >= PERCOLATION_THRESHOLD)
                {
                    grid[i][j] = 2;
                    num_percolation++;
                }
            }
        }
    }

    printf("Number of percolations: %d\n", num_percolation);

    free(grid);

    return 0;
}