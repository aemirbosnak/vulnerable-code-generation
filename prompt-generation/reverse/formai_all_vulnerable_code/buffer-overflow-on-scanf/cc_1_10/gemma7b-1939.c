//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void percolate(int **arr, int n, int i)
{
    int j, k, max_size = 0;

    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            if (arr[j][k] > max_size)
            {
                max_size = arr[j][k];
            }
        }
    }

    arr[i][i] = max_size;
}

int main()
{
    int **arr, n, i;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % MAX;
        }
    }

    for (i = 0; i < n; i++)
    {
        percolate(arr, n, i);
    }

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}