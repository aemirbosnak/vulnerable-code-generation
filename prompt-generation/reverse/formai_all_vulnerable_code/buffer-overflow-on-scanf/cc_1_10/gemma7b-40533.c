//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

void bucketSort(int **arr, int n)
{
    int i, j, k, bucketSize, min, max;
    int *buckets = NULL;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    bucketSize = (max - min) / MAX_SIZE + 1;
    buckets = (int *)malloc(bucketSize * sizeof(int));
    memset(buckets, 0, bucketSize * sizeof(int));

    for (i = 0; i < n; i++)
    {
        k = (arr[i][0] - min) / bucketSize;
        buckets[k]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; buckets[j] > 0; j++)
        {
            arr[j][0] = min + bucketSize * i;
            buckets[j]--;
        }
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
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    bucketSort(arr, n);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}