//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, range;
    int *bucket = NULL;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    range = max - min + 1;
    bucket_size = range / MAX_SIZE;

    bucket = (int *)malloc(bucket_size * MAX_SIZE * sizeof(int));
    for (i = 0; i < bucket_size; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
    {
        k = arr[i] - min;
        bucket[k]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; bucket[j] > 0; j++)
        {
            arr[j] = min + j;
            bucket[j]--;
        }
    }

    free(bucket);
}

int main()
{
    int **arr = NULL;
    int n;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));

    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", arr[i]);

    bucket_sort(arr, n);

    printf("Sorted elements:");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}