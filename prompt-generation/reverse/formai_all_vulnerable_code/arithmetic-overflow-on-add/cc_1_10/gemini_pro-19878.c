//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int bucket_size = max / n;

    int buckets[n];
    for (int i = 0; i < n; i++)
    {
        buckets[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int bucket_index = arr[i] / bucket_size;
        buckets[bucket_index]++;
    }

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i]; j++)
        {
            arr[index++] = i * bucket_size + j * bucket_size;
        }
    }
}

int main()
{
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}