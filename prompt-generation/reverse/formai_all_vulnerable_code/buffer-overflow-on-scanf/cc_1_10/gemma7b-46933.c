//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, **buckets, minValue, maxValue;

    minValue = arr[0][0];
    maxValue = arr[0][0];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] < minValue)
                minValue = arr[i][j];

            if (arr[i][j] > maxValue)
                maxValue = arr[i][j];
        }
    }

    bucketSize = (maxValue - minValue) / MAX + 1;
    buckets = (int *)malloc(bucketSize * sizeof(int));

    for (i = 0; i < bucketSize; i++)
    {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        k = (arr[i][0] - minValue) / MAX;
        buckets[k]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[j][0] = minValue + i * MAX;
        }
    }

    free(buckets);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements:");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    bucketSort(arr, n);

    printf("The sorted elements:");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}