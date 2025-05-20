//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j;
    int max = arr[0];
    int min = arr[0];

    // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max - min;

    // Initialize the number of buckets to be equal to the range
    int numBuckets = range / 10;

    // Create an array of empty buckets
    int buckets[numBuckets];

    // Insert each element into its corresponding bucket
    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / 10;
        buckets[bucketIndex] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < numBuckets; i++) {
        int j = i;
        while (j < n) {
            if (arr[j] < buckets[i]) {
                int temp = arr[j];
                arr[j] = buckets[i];
                buckets[i] = temp;
            }
            j++;
        }
    }

    // Copy the sorted elements back into the original array
    for (i = 0; i < n; i++) {
        arr[i] = buckets[i];
    }
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int i, n;

    // Prompt the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort on the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}