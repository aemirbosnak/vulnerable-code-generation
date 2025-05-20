//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n, int k)
{
    int i, j, h, bucket[k], *temp = NULL;

    temp = (int *)malloc(n * sizeof(int));

    for (i = 0; i < k; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        bucket[*arr[i]]++;
    }

    for (i = 1; i < k; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    h = bucket[k - 1];

    for (i = n - 1; i >= 0; i--)
    {
        temp[bucket[*arr[i]] - 1] = *arr[i];
        bucket[*arr[i]]--;
    }

    for (i = 0; i < n; i++)
    {
        *arr[i] = temp[i];
    }

    free(temp);
}

int main()
{
    int n, k, i, arr[] = {3, 0, 2, 4, 5, 1, 3, 2, 4, 6};

    n = sizeof(arr) / sizeof(int);
    k = 7;

    bucketSort(arr, n, k);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}