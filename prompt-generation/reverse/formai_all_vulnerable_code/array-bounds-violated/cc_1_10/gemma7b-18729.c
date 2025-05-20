//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int **arr, int n)
{
    int i, j, k, buckets[n], min, max;
    min = max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }

    buckets[0] = (int)(max - min) / n + 1;
    for (k = 1; k < n; k++)
    {
        buckets[k] = buckets[k - 1] + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < arr[i][1]; j++)
        {
            arr[i][j] = buckets[arr[i][j]] - 1;
        }
    }
}

int main()
{
    int **arr = NULL;
    int n;

    printf("Enter the number of buckets:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the number of elements:");
    scanf("%d", &arr[0][1]);

    // Input the elements
    for (int i = 0; i < arr[0][1]; i++)
    {
        scanf("%d", &arr[0][i + 1]);
    }

    bucketSort(arr, n);

    // Print the sorted elements
    for (int i = 0; i < arr[0][1]; i++)
    {
        printf("%d ", arr[0][i + 1]);
    }

    return 0;
}