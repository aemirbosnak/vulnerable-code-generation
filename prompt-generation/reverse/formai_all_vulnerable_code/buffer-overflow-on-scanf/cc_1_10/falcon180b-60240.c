//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create n empty buckets
    int *bucket = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        bucket[i] = 0;

    // Put elements in the appropriate bucket
    for (int i = 0; i < n; i++) {
        bucket[arr[i] / max * max]++;
    }

    // Concatenate all the buckets back into the original array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[i * max + j] = i * max + j;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Get elements from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}