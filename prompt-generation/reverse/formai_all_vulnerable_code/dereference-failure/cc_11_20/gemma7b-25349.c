//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_PERCOLATION 10

int main()
{
    int **grid = NULL;
    int x, y, i, j, percolations = 0;
    time_t t;

    grid = (int **)malloc(WIDTH * sizeof(int *));
    for(x = 0; x < WIDTH; x++)
    {
        grid[x] = (int *)malloc(HEIGHT * sizeof(int));
    }

    t = time(NULL);
    for(i = 0; i < MAX_PERCOLATION; i++)
    {
        percolations = 0;
        for(x = 0; x < WIDTH; x++)
        {
            for(y = 0; y < HEIGHT; y++)
            {
                if(grid[x][y] == 1)
                {
                    int neighbors = 0;
                    if(grid[x-1][y] == 1) neighbors++;
                    if(grid[x+1][y] == 1) neighbors++;
                    if(grid[x][y-1] == 1) neighbors++;
                    if(grid[x][y+1] == 1) neighbors++;

                    if(neighbors >= 2)
                    {
                        grid[x][y] = 2;
                        percolations++;
                    }
                }
            }
        }

        printf("Percolations: %d\n", percolations);
    }

    time_t end_t = time(NULL);
    printf("Time taken: %.2lf seconds\n", (double)(end_t - t) / MAX_PERCOLATION);

    return 0;
}