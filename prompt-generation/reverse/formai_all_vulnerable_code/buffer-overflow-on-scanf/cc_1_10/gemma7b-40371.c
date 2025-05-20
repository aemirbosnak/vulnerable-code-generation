//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
        buckets[k][bucket_size] = arr[i];
        bucket_size++;
    }

    for (i = 0; i < n; i++)
    {
        j = buckets[i][0];
        while (buckets[i][0] != NULL)
        {
            arr[j] = buckets[i][0];
            buckets[i][0] = buckets[i][1];
            j++;
        }
    }

    free(buckets);
}

int main()
{
    int n, i, **arr = NULL;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

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

    free(arr);

    return 0;
}