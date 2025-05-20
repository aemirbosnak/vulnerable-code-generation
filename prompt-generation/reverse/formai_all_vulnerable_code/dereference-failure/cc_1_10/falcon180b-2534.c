//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum element in an array
int calculateMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = calculateMax(arr, n);
    int bucketSize = max / n;

    // Create empty buckets
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int *) malloc(bucketSize * sizeof(int));
        for (int j = 0; j < bucketSize; j++) {
            buckets[i][j] = 0;
        }
    }

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] / bucketSize) * bucketSize;
        buckets[bucketIndex][arr[i] % bucketSize]++;
    }

    // Merge the buckets back into the array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j] > 0) {
                int count = buckets[i][j];
                while (count > 0) {
                    arr[index++] = i * bucketSize + j;
                    count--;
                }
            }
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

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}