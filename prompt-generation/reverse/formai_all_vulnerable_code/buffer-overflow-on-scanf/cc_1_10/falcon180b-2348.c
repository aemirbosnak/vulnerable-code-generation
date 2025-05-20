//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int size) {
    int i, j, n;
    int *bucket[MAX_SIZE];

    // Initialize buckets with -1
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *) malloc(size * sizeof(int));
        for (j = 0; j < size; j++) {
            bucket[i][j] = -1;
        }
    }

    // Place elements in buckets
    for (i = 0; i < size; i++) {
        n = arr[i] * MAX_SIZE;
        bucket[n][i] = arr[i];
    }

    // Sort each bucket
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < size - 1; j++) {
                for (n = 0; n < size - j - 1; n++) {
                    if (bucket[i][n] > bucket[i][n + 1]) {
                        int temp = bucket[i][n];
                        bucket[i][n] = bucket[i][n + 1];
                        bucket[i][n + 1] = temp;
                    }
                }
            }
        }
    }

    // Merge sorted buckets
    int mergeIndex = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < size; j++) {
                arr[mergeIndex] = bucket[i][j];
                mergeIndex++;
            }
            mergeIndex += size - 1;
        }
    }

    for (i = mergeIndex; i < MAX_SIZE; i++) {
        arr[i] = -1;
    }
}

int main() {
    int i, n;
    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}