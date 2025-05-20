//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n, int k)
{
    int i, j, h, bucket[k], *ptr;
    ptr = *arr;

    for (i = 0; i < k; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        bucket[ptr[i]]++;
    }

    for (i = 1; i < k; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        ptr[bucket[ptr[i]] - 1] = ptr[i];
        bucket[ptr[i]]--;
    }
}

int main()
{
    int **arr = NULL;
    int n, k, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of buckets: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i][0]);
    }

    bucket_sort(arr, n, k);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i][0]);
    }

    return 0;
}