//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void bucket_sort(int *arr, int n)
{
    int i, j, k, bucket_size, *bucket, **histogram = NULL;

    histogram = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        histogram[i] = (int *)malloc(MAX * sizeof(int));

    bucket_size = MAX / n;
    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        histogram[k][arr[i]]++;
    }

    for (i = 0; i < n; i++)
    {
        k = arr[i] / bucket_size;
        histogram[k][arr[i]]--;
    }

    free(histogram);

    return;
}

int main()
{
    int n, i, *arr;

    scanf("Enter the number of elements: ", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}