//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucketSort(int arr[], int n)
{
    int i, j, k, max, min;
    int *bucket[n];
    for (i = 0; i < n; i++)
        bucket[i] = (int *)malloc(sizeof(int));

    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            arr[i] = -arr[i];
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    double range = (double)(max - min) / n;

    for (i = 0; i < n; i++)
    {
        bucket[i] = (int *)malloc((int)((max - min) / range + 1) * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        k = (int)((arr[i] - min) / range);
        bucket[k] = (int *)realloc(bucket[k], (k + 1) * sizeof(int));
        bucket[k][k] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (int)((max - min) / range); j++)
        {
            if (bucket[j][j]!= 0)
            {
                arr[i] = bucket[j][j];
                bucket[j][j] = 0;
                i++;
                break;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    bucketSort(arr, n);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nCPU time used: %.6f seconds", cpu_time_used);

    return 0;
}