//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, **buckets, key;

    buckets = (int *)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        key = arr[i];
        buckets[key][k++] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; buckets[i][j] != NULL; j++)
        {
            arr[j] = buckets[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    int n, i, **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}