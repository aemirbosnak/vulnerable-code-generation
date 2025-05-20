//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
// Bucket Sort Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define BUCKET_SIZE 5

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n)
{
    int i, j;
    int bucket[BUCKET_SIZE];
    int index;

    // Initialize buckets
    for (i = 0; i < BUCKET_SIZE; i++)
    {
        bucket[i] = 0;
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++)
    {
        index = arr[i] / BUCKET_SIZE;
        bucket[index]++;
    }

    // Sort elements in each bucket
    for (i = 0; i < BUCKET_SIZE; i++)
    {
        // Sort bucket[i]
        for (j = 0; j < bucket[i]; j++)
        {
            // Insertion sort
            int key = arr[i * BUCKET_SIZE + j];
            int k;
            for (k = j - 1; k >= 0 && arr[k] > key; k--)
            {
                arr[k + 1] = arr[k];
            }
            arr[k + 1] = key;
        }
    }
}

// Driver code
int main()
{
    int arr[MAX_ELEMENTS] = {3, 2, 1, 4, 5, 10, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}