//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int **arr;
    int n, m, i, j, k, l, t, x, y;
    srand(time(NULL));

    printf("Enter the number of rows and columns:");
    scanf("%d %d", &n, &m);

    arr = (int **)malloc(n * sizeof(int *));
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

    printf("The matrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of iterations:");
    scanf("%d", &t);

    for (k = 0; k < t; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                l = arr[i][j] & 1;
                if (l == 0)
                {
                    x = rand() % n;
                    y = rand() % m;
                    arr[x][y] = 1;
                }
            }
        }
    }

    printf("The matrix after %d iterations is:\n", t);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}