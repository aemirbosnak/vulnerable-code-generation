//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, **buckets, key;

    buckets = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        key = arr[i];
        buckets[key]++;
    }

    for (i = 0, j = 0; i < n; i++)
    {
        while (buckets[j] > 0)
        {
            arr[i] = arr[j];
            buckets[j]--;
            i++;
        }
        j++;
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

    bucketSort(&arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}