//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max;
    int *bucket = NULL;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            if (min > arr[i][0])
                min = arr[i][0];
            if (max < arr[i][0])
                max = arr[i][0];
        }
    }

    bucket_size = (max - min) / 10 + 1;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    for (i = 0; i < bucket_size; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            bucket[arr[i][0]]++;
        }
    }

    k = 0;
    for (i = min; i <= max; i++)
    {
        for (j = 0; bucket[j] > 0; j++)
        {
            arr[k][0] = i;
            k++;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(2 * sizeof(int));

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i][1]; j++)
            printf("%d ", arr[i][0]);
        printf("\n");
    }

    free(arr);

    return 0;
}