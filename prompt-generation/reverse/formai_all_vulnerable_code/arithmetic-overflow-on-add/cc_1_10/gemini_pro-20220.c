//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array using bucket sort
void bucketSort(int arr[], int n) 
{
    // Create n empty buckets
    int buckets[n];
    for (int i = 0; i < n; i++) 
    {
        buckets[i] = 0;
    }

    // Distribute the elements into the buckets
    for (int i = 0; i < n; i++) 
    {
        buckets[arr[i]]++;
    }

    // Concatenate the buckets into the sorted array
    int index = 0;
    for (int i = 0; i < n; i++) 
    {
        while (buckets[i] > 0) 
        {
            arr[index++] = i;
            buckets[i]--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code to test the bucket sort function
int main() 
{
    int arr[] = { 4, 6, 2, 8, 3, 9, 7, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}