//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
/*
 * Bucket Sort Implementation Example in C
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 10

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void bucket_sort(int *arr, int size) {
    int *buckets[NUM_BUCKETS];
    int i, j, k, m;

    // Create buckets
    for (i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = malloc(size * sizeof(int));
    }

    // Distribute elements into buckets
    for (i = 0; i < size; i++) {
        j = arr[i] / (size / NUM_BUCKETS);
        buckets[j][k++] = arr[i];
    }

    // Sort each bucket
    for (i = 0; i < NUM_BUCKETS; i++) {
        qsort(buckets[i], k, sizeof(int), compare);
    }

    // Merge buckets
    m = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < k; j++) {
            arr[m++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {3, 0, 2, 5, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}