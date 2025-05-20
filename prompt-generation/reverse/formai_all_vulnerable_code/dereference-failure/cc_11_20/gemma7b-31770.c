//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, m, t, i, j, k;
    n = 10;
    m = 10;
    t = 100;

    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < t; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    int dx[] = {1, -1, 0, 0};
                    int dy[] = {0, 0, 1, -1};

                    for (int l = 0; l < 4; l++)
                    {
                        int x = i + dx[l];
                        int y = j + dy[l];

                        if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 0)
                        {
                            arr[x][y] = 1;
                        }
                    }
                }
            }
        }
    }

    free(arr);

    return 0;
}