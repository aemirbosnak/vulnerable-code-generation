//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, *bucket;

    bucket_size = n / MAX_SIZE;
    bucket = (int *)malloc(bucket_size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        bucket[k]++;
    }

    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; bucket[j] > 0; j++)
        {
            arr[j] = i * bucket_size + j;
            bucket[j]--;
        }
    }

    free(bucket);
}

int main()
{
    int n, i, arr[MAX_SIZE];

    printf("Enter the number of elements:");
    scanf("%d", &n);

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

    return 0;
}