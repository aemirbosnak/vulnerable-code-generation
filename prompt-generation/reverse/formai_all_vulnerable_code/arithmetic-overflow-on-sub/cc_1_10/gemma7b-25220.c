//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, **bucket, min, max;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / MAX + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    for (i = 0; i < bucket_size; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        bucket[k]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[j][0] = min + i * MAX;
        }
    }

    free(bucket);
}

int main()
{
    int n, i, **arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        arr[i][0] = scanf("%d", &arr[i][0]);
    }

    bucket_sort(arr, n);

    printf("Sorted elements:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    return 0;
}