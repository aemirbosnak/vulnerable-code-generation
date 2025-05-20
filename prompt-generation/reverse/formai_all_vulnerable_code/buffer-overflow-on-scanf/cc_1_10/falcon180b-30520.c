//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of array

// Function to sort an array using Bucket Sort
void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[MAX_SIZE]; // Create an array of buckets

    // Find the range of elements in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the size of each bucket
    int size = (max - min + 1) / n;

    // Place each element in its respective bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / size;
        bucket[j] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bucket[j] < bucket[i]) {
                temp = bucket[i];
                bucket[i] = bucket[j];
                bucket[j] = temp;
            }
        }
    }

    // Copy the sorted elements back to the original array
    for (i = 0; i < n; i++) {
        arr[i] = bucket[i];
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Read the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using Bucket Sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}