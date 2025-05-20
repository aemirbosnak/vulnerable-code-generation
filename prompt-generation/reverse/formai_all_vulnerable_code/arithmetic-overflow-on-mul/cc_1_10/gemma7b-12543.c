//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int **arr, i, j, k, x, y, z;
    int n, m, h;

    printf("Enter the dimensions of the grid (n, m, h): ");
    scanf("%d %d %d", &n, &m, &h);

    arr = (int *)malloc(n * m * h * sizeof(int));
    for (i = 0; i < n * m * h; i++)
    {
        arr[i] = 0;
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    for (x = 0; x < k; x++)
    {
        for (y = 0; y < n; y++)
        {
            for (z = 0; z < m; z++)
            {
                if (arr[y * m * h + z] == 0)
                {
                    rand_r(&z);
                    if (rand_r(&z) % 2 == 0)
                    {
                        arr[y * m * h + z] = 1;
                    }
                }
            }
        }
    }

    printf("The percolated grid: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < h; k++)
            {
                printf("%d ", arr[i * m * h + j]);
            }
            printf("\n");
        }
    }

    free(arr);

    return 0;
}