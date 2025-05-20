//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
/*
 * A unique C Bucket Sort Implementation example program in a Sherlock Holmes style.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
#define NUM_BUCKETS 10

void bucket_sort(int arr[], int n) {
    int i, j, bucket[NUM_BUCKETS][BUCKET_SIZE];

    // Initialize buckets
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            bucket[i][j] = -1;
        }
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        int pos = arr[i] % BUCKET_SIZE;
        bucket[index][pos] = arr[i];
    }

    // Sort buckets
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (bucket[i][j] != -1) {
                arr[i * BUCKET_SIZE + j] = bucket[i][j];
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 4, 3, 8, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}