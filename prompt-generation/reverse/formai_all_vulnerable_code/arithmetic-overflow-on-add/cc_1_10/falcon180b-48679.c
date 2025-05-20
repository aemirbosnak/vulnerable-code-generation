//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, max, min;
    int bucket[MAX_SIZE];
    int count[MAX_SIZE] = { 0 };

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the size of each bucket
    int bucketSize = (max - min) / n;

    // Place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j] = arr[i];
        count[j]++;
    }

    // Sort each bucket using a sorting algorithm
    for (i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            count[i] = 0;
            for (j = i + 1; j < MAX_SIZE; j++) {
                if (bucket[j] < bucket[i]) {
                    int temp = bucket[i];
                    bucket[i] = bucket[j];
                    bucket[j] = temp;
                }
            }
        }
    }

    // Place the sorted elements back into the original array
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        arr[i] = bucket[j];
    }
}

int main() {
    int arr[] = { 5, 2, 8, 9, 1, 6, 3, 7, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}