//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
{
    int i, j, bucket_size, *bucket = NULL;

    bucket_size = k;
    bucket = (int *)malloc(bucket_size * sizeof(int));
    for (i = 0; i < n; i++)
    {
        bucket[*arr[i]]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        if (bucket[i] > 0)
        {
            for (j = 0; j < bucket[i]; j++)
            {
                arr[j] = i;
            }
        }
    }

    free(bucket);
}

int main()
{
    int n, k, i, **arr = NULL;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the number of buckets:");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n, k);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}