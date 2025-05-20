//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main()
{
    int i, j, k, x, y, z, n, m, **arr, **p;

    n = DIM;
    m = DIM;
    arr = (int *)malloc(n * m * sizeof(int));
    p = (int *)malloc(n * m * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i * m + j] = rand() % 2;
            p[i * m + j] = 0;
        }
    }

    for (k = 0; k < 1000; k++)
    {
        x = rand() % n;
        y = rand() % m;

        if (arr[x * m + y] == 1 && p[x * m + y] == 0)
        {
            p[x * m + y] = 1;

            for (z = -1; z <= 1; z++)
            {
                if (x + z >= 0 && x + z < n && p[ (x + z) * m + y] == 0)
                {
                    p[ (x + z) * m + y] = 1;
                }
            }

            for (z = -1; z <= 1; z++)
            {
                if (y + z >= 0 && y + z < m && p[x * m + (y + z)] == 0)
                {
                    p[x * m + (y + z)] = 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", p[i * m + j]);
        }
        printf("\n");
    }

    free(arr);
    free(p);

    return 0;
}