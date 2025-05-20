//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int **arr, int n, int k)
{
    int i, j, count[k], *bucket[k];

    for (i = 0; i < k; i++)
    {
        bucket[i] = (int *)malloc(n * sizeof(int));
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        bucket[*arr[i]]++;
        count[*arr[i]]++;
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            arr[j] = bucket[i];
        }
    }

    for (i = 0; i < k; i++)
    {
        free(bucket[i]);
    }
}

int main()
{
    int n, k, **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of buckets: ");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n, k);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}