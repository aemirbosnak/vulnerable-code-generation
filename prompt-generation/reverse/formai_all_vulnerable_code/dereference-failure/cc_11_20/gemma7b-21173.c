//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int x, y, z, i, j, k;

    grid = (int**)malloc(WIDTH * sizeof(int*));
    for(x = 0; x < WIDTH; x++)
    {
        grid[x] = (int*)malloc(HEIGHT * sizeof(int));
    }

    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = rand() % 2;
        }
    }

    for(z = 0; z < 1000; z++)
    {
        for(i = 0; i < WIDTH; i++)
        {
            for(j = 0; j < HEIGHT; j++)
            {
                if(grid[i][j] == 1)
                {
                    k = rand() % 4;
                    switch(k)
                    {
                        case 0:
                            grid[i][j] = 0;
                            break;
                        case 1:
                            if(i > 0) grid[i - 1][j] = 1;
                            break;
                        case 2:
                            if(j > 0) grid[i][j - 1] = 1;
                            break;
                        case 3:
                            if(i < WIDTH - 1) grid[i + 1][j] = 1;
                            break;
                        case 4:
                            if(j < HEIGHT - 1) grid[i][j + 1] = 1;
                            break;
                    }
                }
            }
        }
    }

    for(x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}