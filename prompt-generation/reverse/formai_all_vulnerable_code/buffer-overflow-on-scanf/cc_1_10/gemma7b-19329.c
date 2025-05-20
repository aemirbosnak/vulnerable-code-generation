//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, **buckets;

    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i];
        buckets[k][i] = arr[i];
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
    int n, i, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}