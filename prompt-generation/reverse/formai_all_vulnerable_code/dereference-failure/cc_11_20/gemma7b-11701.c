//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **arr = NULL;
    int i, j, k, l, r, x, y;

    arr = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    x = rand() % MAX;
    y = rand() % MAX;
    arr[x][y] = 1;

    for (l = 0; l < MAX; l++)
    {
        for (r = 0; r < MAX; r++)
        {
            if (arr[l][r] == 1)
            {
                if (l - 1 >= 0 && arr[l - 1][r] == 0)
                {
                    arr[l - 1][r] = 1;
                }
                if (r - 1 >= 0 && arr[l][r - 1] == 0)
                {
                    arr[l][r - 1] = 1;
                }
                if (l + 1 < MAX && arr[l + 1][r] == 0)
                {
                    arr[l + 1][r] = 1;
                }
                if (r + 1 < MAX && arr[l][r + 1] == 0)
                {
                    arr[l][r + 1] = 1;
                }
            }
        }
    }

    free(arr);

    return 0;
}