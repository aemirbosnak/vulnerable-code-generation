//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void bucketSort(int arr[], int n)
{
    int i, j, k, bucket[MAX], count[MAX] = {0};

    for (i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }

    for (j = 0; j < MAX; j++)
    {
        count[j] += bucket[j];
    }

    int output[n];
    k = 0;

    for (i = 0; i < n; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {4, 3, 5, 2, 8, 6, 1, 9, 7, 0};
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