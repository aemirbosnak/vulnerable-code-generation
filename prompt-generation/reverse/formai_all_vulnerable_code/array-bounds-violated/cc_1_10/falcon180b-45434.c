//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get the maximum value from an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucketSize = max/n;
    int* buckets[n];

    // Initialize all buckets to empty
    for(int i=0; i<n; i++) {
        buckets[i] = (int*)malloc(sizeof(int)*bucketSize);
        for(int j=0; j<bucketSize; j++) {
            buckets[i][j] = -1;
        }
    }

    // Place elements in buckets
    for(int i=0; i<n; i++) {
        int bucketIndex = arr[i]/bucketSize;
        buckets[bucketIndex][arr[i]%bucketSize] = arr[i];
    }

    // Sort each bucket using insertion sort
    for(int i=0; i<n; i++) {
        int j = 0;
        for(int k=0; k<bucketSize; k++) {
            if(buckets[i][k]!= -1) {
                arr[j] = buckets[i][k];
                j++;
            }
        }
        while(j<bucketSize) {
            arr[j] = -1;
            j++;
        }
    }

    // Free memory allocated for buckets
    for(int i=0; i<n; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}