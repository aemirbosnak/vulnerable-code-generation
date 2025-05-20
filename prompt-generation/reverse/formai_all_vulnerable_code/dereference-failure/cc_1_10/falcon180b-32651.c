//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max / n + 1;
    int *buckets[n];

    // Create empty buckets
    for(int i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
        for(int j = 0; j < bucketSize; j++) {
            buckets[i][j] = 0;
        }
    }

    // Put elements in the appropriate buckets
    for(int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex][arr[i] % bucketSize]++;
    }

    // Merge buckets and update array
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bucketSize; j++) {
            if(buckets[i][j] > 0) {
                arr[index++] = j * bucketSize + i * bucketSize;
                buckets[i][j]--;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

// Driver program
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}