//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(int *input, int n) {
    // Create n empty buckets
    int **buckets = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(sizeof(int) * n);
    }

    // Initialize all buckets to empty
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = input[i] / n;
        buckets[bucketIndex][i] = input[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        // Insertion sort
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

    // Concatenate all buckets into input array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input[index++] = buckets[i][j];
        }
    }

    // Free memory
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

// Driver code
int main() {
    // Get input array
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *input = malloc(sizeof(int) * n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    // Perform bucket sort
    bucketSort(input, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(input, n);

    // Free memory
    free(input);
    return 0;
}