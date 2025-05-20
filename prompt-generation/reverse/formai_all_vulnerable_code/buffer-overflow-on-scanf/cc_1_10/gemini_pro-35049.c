//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort
void bucketSort(int *arr, int n) {

    // Create n empty buckets
    int **buckets = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(n * sizeof(int));
    }

    // Distribute the elements into the buckets
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / n;
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex][i] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate the sorted buckets into arr
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    int *arr = malloc(n * sizeof(int));
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