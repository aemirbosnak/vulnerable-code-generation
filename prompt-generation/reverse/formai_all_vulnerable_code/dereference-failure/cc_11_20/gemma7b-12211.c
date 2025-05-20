//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, m, k;
    scanf("Enter the number of rows and columns:", &n);
    scanf("Enter the number of iterations:", &k);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    srand(time(NULL));
    for (int iter = 0; iter < k; iter++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = rand() % 2;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    int dx[] = {0, 1, 0, -1};
                    int dy[] = {1, 0, -1, 0};
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}