//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, *bucket, **sorted_arr;

    sorted_arr = (int **)malloc(n * sizeof(int *));
    bucket = (int *)malloc((n / bucket_size) * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
        sorted_arr[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] / bucket_size;
        bucket[k]++;
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] / bucket_size;
        sorted_arr[bucket[k]] = arr[i];
        bucket[k]--;
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(bucket);
    free(sorted_arr);
}

int main()
{
    int n, i, **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i][0]);
    }

    bucket_sort(arr, n);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}