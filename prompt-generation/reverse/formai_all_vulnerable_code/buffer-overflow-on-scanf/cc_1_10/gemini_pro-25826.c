//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to sort the elements of an array using bucket sort
void bucketSort(int arr[], int n) {
    // Create n empty buckets
    int buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Count the number of elements in each bucket
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Place the elements back into the array in sorted order
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (buckets[i] > 0) {
            arr[j++] = i;
            buckets[i]--;
        }
    }
}

// Function to print the elements of an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Get the size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("The sorted array is: ");
    printArray(arr, n);

    return 0;
}