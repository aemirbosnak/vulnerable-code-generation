//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;
    bucket_size = n / 10 + 1;
    min = arr[0][0];
    max = arr[0][1];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (min > arr[i][j])
                min = arr[i][j];
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j][0] == i)
            {
                for (k = 0; k < 2; k++)
                {
                    printf("%d ", arr[j][k]);
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    int n, i, j;
    int **arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    bucket_sort(arr, n);
    return 0;
}