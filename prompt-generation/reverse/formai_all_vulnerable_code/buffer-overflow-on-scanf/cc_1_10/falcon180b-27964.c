//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket[n];
    int max = arr[0], min = arr[0];

    // Find max and min values in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Create empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * bucketSize);
    }

    // Put elements into buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j] = realloc(bucket[j], sizeof(int) * (k = ++bucket[j][0]));
        bucket[j][k - 1] = arr[i];
    }

    // Sort elements within each bucket
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            for (k = j + 1; k < bucket[i][0]; k++) {
                if (bucket[i][j] > bucket[i][k]) {
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }

    // Copy sorted elements back to original array
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[j * n + i] = bucket[i][j];
        }
    }
}

int main() {
    int i, n;
    int *arr;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;
    arr = (int *) malloc(sizeof(int) * n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}