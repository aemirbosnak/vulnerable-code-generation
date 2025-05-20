//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Alan Turing
#include <stdlib.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512

int main()
{
    int **grid = (int**)malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    srand(time(NULL));

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            grid[y][x] = rand() % 2;
        }
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (grid[y][x] == 1)
            {
                int dx[] = { -1, 1, 0, 0 };
                int dy[] = { 0, 0, -1, 1 };

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && grid[ny][nx] == 0)
                    {
                        grid[ny][nx] = 1;
                    }
                }
            }
        }
    }

    free(grid);

    return 0;
}