//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void bucketSortMulti(int **arr, int n)
{
    int i, j, k, bucketSize, min, max, hashValue;
    int *buckets = NULL;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++)
    {
        min = arr[i][0] < min ? arr[i][0] : min;
        max = arr[i][0] > max ? arr[i][0] : max;
    }

    bucketSize = (max - min) / MAX_SIZE + 1;
    buckets = (int *)malloc(bucketSize * sizeof(int));
    memset(buckets, 0, bucketSize * sizeof(int));

    for (i = 0; i < n; i++)
    {
        hashValue = (arr[i][0] - min) / bucketSize;
        buckets[hashValue]++;
    }

    for (i = 0; i < bucketSize; i++)
    {
        for (j = 0; buckets[j] > 0; j++)
        {
            for (k = 0; k < buckets[j]; k++)
            {
                arr[k][0] = min + j * MAX_SIZE;
            }
        }
    }

    free(buckets);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of players:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    bucketSortMulti(arr, n);

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