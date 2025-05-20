//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
 
// Function to perform bucket sort
void bucketSort(int arr[], int n)
{
    // Create buckets 
    int buckets[10][n];
 
    // Initialize bucket counts as 0
    int bucket_count[10] = { 0 };
 
    // Calculate maximum element from the array
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max)
            max = arr[i];
    }
 
    // Increment bucket count for each element
    for (int i = 0; i < n; i++) 
    {
        int bucket_index = ((float)arr[i] / (float)max) * 10;
        buckets[bucket_index][bucket_count[bucket_index]++] = arr[i];
    }
 
    // Sort elements in each bucket
    for (int i = 0, j = 0; i < 10; i++) 
    {
        int k = 0;
        while (k < bucket_count[i]) 
        {
            arr[j++] = buckets[i][k++];
        }
    }
}
 
int main()
{
    int arr[] = { 3, 1, 4, 8, 7, 5, 2, 6, 9, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    // Sort the array using Bucket Sort
    bucketSort(arr, n);
 
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
 
    return 0;
}