//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Returns the maximum element in the array
int getMaxElement(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Bucket Sort Implementation
void bucketSort(int arr[], int n) {
    int i, j, index = 0;
    int max = getMaxElement(arr, n);
    int bucket[BUCKET_SIZE];

    for(i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = 0;
    }

    for(i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for(i = 0; i < BUCKET_SIZE; i++) {
        for(j = 0; j < bucket[i]; j++) {
            arr[index++] = i;
        }
    }
}

// Main Function
int main() {
    int arr[] = {4, 1, 9, 10, 5, 8, 3, 6, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}