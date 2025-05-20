//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int main()
{
    int **grid = NULL;
    int x, y, i, j, seed, percolate = 0;

    seed = time(NULL);
    srand(seed);

    grid = (int **)malloc(WIDTH * sizeof(int *));
    for(i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = rand() % 2;
        }
    }

    percolate = 0;
    while(!percolate)
    {
        for(x = 0; x < WIDTH; x++)
        {
            for(y = 0; y < HEIGHT; y++)
            {
                if(grid[x][y] == 1)
                {
                    int dir = rand() % 4;

                    switch(dir)
                    {
                        case UP:
                            if(grid[x][y - 1] == 0)
                            {
                                grid[x][y] = 0;
                                percolate++;
                            }
                            break;
                        case DOWN:
                            if(grid[x][y + 1] == 0)
                            {
                                grid[x][y] = 0;
                                percolate++;
                            }
                            break;
                        case LEFT:
                            if(grid[x - 1][y] == 0)
                            {
                                grid[x][y] = 0;
                                percolate++;
                            }
                            break;
                        case RIGHT:
                            if(grid[x + 1][y] == 0)
                            {
                                grid[x][y] = 0;
                                percolate++;
                            }
                            break;
                    }
                }
            }
        }
    }

    free(grid);

    return 0;
}