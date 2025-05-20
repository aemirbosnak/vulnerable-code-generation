//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int **arr, int n, int k)
{
    int i, j, x, bucket[k], *temp = NULL;

    temp = (int *)malloc(n * sizeof(int));

    for (i = 0; i < k; i++)
    {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        x = arr[i];
        bucket[x]++;
    }

    for (i = 1; i < k; i++)
    {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        x = arr[i];
        temp[bucket[x] - 1] = x;
        bucket[x]--;
    }

    free(temp);

    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int n, k, i, arr[10] = {1, 3, 5, 2, 4, 3, 2, 4, 6, 5};

    n = sizeof(arr) / sizeof(int);
    k = 7;

    bucket_sort(arr, n, k);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}