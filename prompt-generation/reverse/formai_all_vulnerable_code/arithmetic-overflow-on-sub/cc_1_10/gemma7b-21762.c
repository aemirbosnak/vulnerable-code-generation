//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, **buckets, min, max;
    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }
    bucketSize = (max - min) / MAX + 1;
    buckets = (int **)malloc(bucketSize * sizeof(int *));
    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        buckets[arr[i][0]]++;
    }
    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[j][0] = i;
        }
    }
    free(buckets);
}

int main()
{
    int n, i, j, **arr;
    scanf("Enter the number of elements: ", &n);
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        scanf("Enter the element: ", &arr[i][0]);
        scanf("Enter the element: ", &arr[i][1]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element: %d, Index: %d\n", arr[i][0], arr[i][1]);
    }
    free(arr);
    return 0;
}