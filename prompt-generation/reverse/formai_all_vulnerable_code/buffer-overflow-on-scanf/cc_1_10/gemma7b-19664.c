//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void bucket_sort(int **arr, int n)
{
    int i, j, k, bucket_size, min, max, **buckets;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / MAX + 1;
    buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        buckets[arr[i][0]]++;
    }

    for (i = 0; i < bucket_size; i++)
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
    int i, n, **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    bucket_sort(arr, n);

    printf("The sorted elements are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d %d ", arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}