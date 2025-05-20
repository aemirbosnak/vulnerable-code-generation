//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to get maximum element in an array
int getMax(int arr[], int n) {
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
    int max = getMax(arr, n);
    int bucketSize = max / n;
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((arr[j] / bucketSize) == i) {
                int k = 0;
                while (k < bucketSize && ((j + k) * bucketSize <= max)) {
                    buckets[i][k] = arr[j];
                    k++;
                }
            }
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[] = { 5, 2, 9, 1, 7, 8, 3, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}