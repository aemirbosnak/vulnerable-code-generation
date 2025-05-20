//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Bucket size is a constant that can be tuned for performance
#define BUCKET_SIZE 1000

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n)
{
    // Create an array to hold the minimum element from each bucket
    int min_ele[BUCKET_SIZE];

    // Create an array to hold the count of elements in each bucket
    int bucket_count[BUCKET_SIZE];

    // Iterate over each element in the array
    for (int i = 0; i < n; i++)
    {
        // Calculate the index of the bucket for the current element
        int bucket_index = arr[i] / BUCKET_SIZE;

        // Update the count of elements in the current bucket
        bucket_count[bucket_index]++;

        // If the current element is smaller than the minimum element in the current bucket,
        // update the minimum element
        if (arr[i] < min_ele[bucket_index])
            min_ele[bucket_index] = arr[i];
    }

    // Allocate memory for the sorted array
    int *sorted_arr = (int*)malloc(n * sizeof(int));

    // Copy the minimum elements from each bucket to the sorted array
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        if (bucket_count[i] > 0)
        {
            sorted_arr[i] = min_ele[i];
            bucket_count[i]--;
        }
    }

    // Copy the remaining elements from the original array to the sorted array
    for (int i = BUCKET_SIZE; i < n; i++)
    {
        sorted_arr[i] = arr[i];
    }

    // Free the memory for the original array
    free(arr);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sorted_arr[i]);
    }
}

int main()
{
    // Create an array of size 10
    int arr[] = {10, 2, 8, 4, 5, 1, 3, 7, 6, 9};

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, 10);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}