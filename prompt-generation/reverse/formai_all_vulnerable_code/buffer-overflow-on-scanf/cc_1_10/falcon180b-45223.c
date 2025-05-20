//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bucketSort(int arr[], int size)
{
    int i, j, n, max, min, temp, *bucket[MAX];
    for (i = 0; i < MAX; i++)
        bucket[i] = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        n = arr[i] * MAX / (MAX - 1);
        bucket[n] = (int *)realloc(bucket[n], (n + 1) * sizeof(int));
        bucket[n][n] = arr[i];
    }

    for (i = MAX - 1; i >= 0; i--)
    {
        if (bucket[i]!= NULL)
        {
            for (j = 0; j <= size - 1; j++)
            {
                arr[j] = bucket[i][j];
            }
            size = size - (MAX - i);
        }
    }
}

int main()
{
    int i, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    srand(time(NULL));

    for (i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("After sorting:\n");
    printArray(arr, size);

    return 0;
}