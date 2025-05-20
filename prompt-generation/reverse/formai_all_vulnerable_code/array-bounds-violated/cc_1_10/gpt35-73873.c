//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {

    // Create an array of empty buckets
    int bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Determine the range of input values
    float min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the size of each bucket
    float bucketSize = (max - min) / n;

    // Distribute input array values into the buckets
    for (int i = 0; i < n; i++) {

        // Determine the index of the bucket for this value
        int bucketIndex = (int)((arr[i] - min) / bucketSize);

        // Increment the count for this bucket
        bucket[bucketIndex]++;
    }

    // Sort each bucket individually
    for (int i = 0; i < n; i++) {

        // Get the count for this bucket
        int count = bucket[i];

        // Sort the values in this bucket
        for (int j = 0; j < count; j++) {
            printf("Bucket #%d, Element %d: %f\n", i+1, j+1, arr[i]);
        }
    }
}

int main() {

    // Test data
    float arr[] = {0.54, 0.29, 0.33, 0.13, 0.24, 0.22, 0.55};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using Bucket Sort
    bucketSort(arr, n);

    return 0;
}