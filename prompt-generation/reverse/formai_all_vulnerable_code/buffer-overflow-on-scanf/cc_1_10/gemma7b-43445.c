//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

#define DIM 20

void percolat(int **arr, int n, int r)
{
    int i, j, k;

    if (r == n)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        return;
    }

    for (k = 0; k < DIM; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (arr[i][j] == k)
                {
                    arr[i][j] = r;
                    percolat(arr, n, r + 1);
                }
            }
        }
    }
}

int main()
{
    int **arr;
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    percolat(arr, n, 0);

    return 0;
}