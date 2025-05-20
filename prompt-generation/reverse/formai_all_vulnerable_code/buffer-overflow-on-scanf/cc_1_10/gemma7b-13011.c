//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n)
{
    int i, j, k, min, max, bucket_size, **buckets, count = 0;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucket_size = (max - min) / n + 1;
    buckets = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i][0] - min;
        buckets[k][count] = i;
        count++;
    }

    for (i = 0; i < n; i++)
    {
        arr[i][0] = buckets[k][count];
        count--;
    }

    free(buckets);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    bucket_sort(arr, n);

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }

    free(arr);

    return 0;
}