//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100

// Function to find the minimum and maximum values in the array
void findMinMax(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int min, max, range;
    findMinMax(arr, n, &min, &max);
    range = max - min + 1;

    // Create empty buckets
    int buckets[MAX_BUCKETS];
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = 0;
    }

    // Add elements to buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / range * MAX_BUCKETS;
        buckets[bucketIndex]++;
    }

    // Sort elements in each bucket
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = min + i * range;
        }
    }
}

int main() {
    int n, arr[100];

    // Read input array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}