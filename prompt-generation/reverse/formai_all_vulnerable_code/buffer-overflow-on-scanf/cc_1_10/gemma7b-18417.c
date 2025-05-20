//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
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
    int n, k, i, **arr = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of buckets: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    bucket_sort(arr, n, k);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}