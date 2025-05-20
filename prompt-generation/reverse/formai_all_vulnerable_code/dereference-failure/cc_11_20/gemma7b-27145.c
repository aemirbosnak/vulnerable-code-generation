//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_SIM_TIME 1000

int main()
{
    int **grid = (int **)malloc(HEIGHT * sizeof(int *)), *ptr;
    int i, j, t, water_drops = 0, current_drops = 0;
    srand(time(NULL));

    for (i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
        for (j = 0; j < WIDTH; j++)
        {
            grid[i][j] = 0;
        }
    }

    for (t = 0; t < MAX_SIM_TIME; t++)
    {
        current_drops = water_drops;
        water_drops = 0;
        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                if (grid[i][j] == 1)
                {
                    int dx[] = {0, 1, 0, -1};
                    int dy[] = {1, 0, -1, 0};
                    for (int k = 0; k < 4; k++)
                    {
                        int x = j + dx[k];
                        int y = i + dy[k];
                        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[y][x] == 0)
                        {
                            grid[y][x] = 1;
                            water_drops++;
                        }
                    }
                }
            }
        }
        if (current_drops != water_drops)
        {
            printf("Water percolates!\n");
            break;
        }
    }

    return 0;
}