//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **arr = NULL;
    int x, y;

    arr = (int**)malloc(WIDTH * sizeof(int*));
    for (x = 0; x < WIDTH; x++)
    {
        arr[x] = (int*)malloc(HEIGHT * sizeof(int));
    }

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            arr[x][y] = rand() % 2;
        }
    }

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (arr[x][y] == 1)
            {
                int dx[] = {1, -1, 0, 0};
                int dy[] = {0, 0, 1, -1};

                for (int i = 0; i < 4; i++)
                {
                    int xx = x + dx[i];
                    int yy = y + dy[i];

                    if (xx >= 0 && xx < WIDTH && yy >= 0 && yy < HEIGHT && arr[xx][yy] == 0)
                    {
                        arr[xx][yy] = 1;
                    }
                }
            }
        }
    }

    free(arr);

    return 0;
}