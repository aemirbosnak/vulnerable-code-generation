//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, **buckets = NULL;

    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        buckets[k][bucket_size]++;
    }

    for (i = 0; i < n; i++)
    {
        bucket_size = buckets[i][0] - 1;
        for (j = 0; j < bucket_size; j++)
        {
            arr[i] = buckets[i][j + 1];
        }
    }

    free(buckets);
}

int main()
{
    int n, i, arr[MAX];

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}