//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 8
#define HEIGHT 8

#define FILL_PERE 50

int main()
{
    int **grid = NULL;
    int i, j, k, r, s, water_level = 0;

    grid = (int **)malloc(WIDTH * sizeof(int *));
    for (i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    srand(time(NULL));

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % FILL_PERE;
        }
    }

    while (water_level < HEIGHT)
    {
        for (k = 0; k < WIDTH; k++)
        {
            for (r = 0; r < HEIGHT; r++)
            {
                if (grid[k][r] == 0)
                {
                    s = rand() % 4;
                    switch (s)
                    {
                        case 0:
                            if (grid[k - 1][r] == 1)
                                grid[k][r] = 1;
                            break;
                        case 1:
                            if (grid[k + 1][r] == 1)
                                grid[k][r] = 1;
                            break;
                        case 2:
                            if (grid[k][r - 1] == 1)
                                grid[k][r] = 1;
                            break;
                        case 3:
                            if (grid[k][r + 1] == 1)
                                grid[k][r] = 1;
                            break;
                    }
                }
            }
        }

        water_level++;
    }

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