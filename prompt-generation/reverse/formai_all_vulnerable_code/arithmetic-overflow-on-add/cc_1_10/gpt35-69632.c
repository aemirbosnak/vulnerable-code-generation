//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Utility function to print an array
void print_array(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bucket sort function
void bucket_sort(int arr[], int n, int max_val)
{
    int i, j, idx;

    // Create n empty buckets
    int buckets[n];

    // Initialize all buckets to 0
    for (i = 0; i < n; i++)
    {
        buckets[i] = 0;
    }

    // Increment the count of the corresponding bucket
    // for each element in the input array
    for (i = 0; i < n; i++)
    {
        idx = (arr[i] / max_val) * n;
        buckets[idx]++;
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < n; i++)
    {
        for (j = i; j > 0 && buckets[j] < buckets[j-1]; j--)
        {
            int temp = buckets[j-1];
            buckets[j-1] = buckets[j];
            buckets[j] = temp;
        }
    }

    // Combine the sorted buckets into the output array
    int k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < buckets[i]; j++)
        {
            arr[k++] = i * max_val + j;
        }
    }
}

int main()
{
    int arr[] = {15, 13, 12, 10, 8, 7, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array:\n");
    print_array(arr, n);

    // Find the maximum value in the input array
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n, max_val);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}