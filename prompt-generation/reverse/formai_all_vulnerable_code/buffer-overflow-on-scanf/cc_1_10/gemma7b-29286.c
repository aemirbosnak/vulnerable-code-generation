//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, key, count = 0;
    int *buckets = NULL;

    buckets = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        buckets[i] = 0;

    for (i = 0; i < n; i++)
    {
        key = arr[i];
        buckets[key]++;
    }

    for (i = 0; i < n; i++)
    {
        count = buckets[i];
        for (j = 0; j < count; j++)
        {
            arr[k] = i;
            k++;
        }
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
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}