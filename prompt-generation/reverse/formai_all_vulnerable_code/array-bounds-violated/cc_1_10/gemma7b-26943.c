//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(int a, int b)
{
    return a - b;
}

void bucketSort(int *arr, int n)
{
    int i, j, k, min, max, buckets[n], bucket[n];

    min = arr[0];
    max = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    buckets[0] = (max - min) / n + 1;

    for (i = 1; i < n; i++)
    {
        buckets[i] = buckets[i - 1] + 1;
    }

    bucket[buckets[0]] = arr[0];

    for (i = 1; i < n; i++)
    {
        bucket[buckets[i]] = arr[i];
    }

    int index = 0;

    for (i = 0; i < n; i++)
    {
        arr[i] = bucket[index];
        index++;
    }
}

int main()
{
    int arr[] = {4, 3, 8, 6, 2, 5, 1, 9, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}