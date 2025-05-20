//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int *arr, int n)
{
    int i, j, k, bucket_size = 10, buckets[bucket_size];

    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]++;
    }

    for (i = 1; i < bucket_size; i++)
    {
        buckets[i] += buckets[i - 1];
    }

    k = 0;
    for (i = 0; i < n; i++)
    {
        buckets[arr[i]]--;
        arr[k] = arr[i];
        k++;
    }
}

int main()
{
    int *arr, n, i;

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

    return 0;
}