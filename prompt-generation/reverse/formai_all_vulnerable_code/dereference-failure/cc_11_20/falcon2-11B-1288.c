//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Bucket Sort Implementation
int main() {
    // Define array
    int arr[] = {9, 2, 5, 1, 7, 4, 6, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calculate maximum number of buckets
    int max_bucket = n / 2;
    if (n % 2 == 0) {
        max_bucket--;
    }

    // Allocate memory for buckets
    int **buckets = malloc(max_bucket * sizeof(int *));
    for (int i = 0; i < max_bucket; i++) {
        buckets[i] = malloc(sizeof(int));
    }

    // Insert elements into buckets
    int *p = arr;
    int bucket_idx = 0;
    while (bucket_idx < max_bucket && p < arr + n) {
        int *bucket = buckets[bucket_idx];
        while (*bucket < *p) {
            ++bucket;
        }
        if (*bucket == max_bucket) {
            buckets[++bucket_idx] = bucket;
            *bucket = *p;
        } else {
            *bucket = *p;
        }
        ++p;
    }

    // Copy elements from buckets to sorted array
    int *q = arr;
    for (int i = 0; i < max_bucket; i++) {
        int *bucket = buckets[i];
        while (bucket > buckets[i]) {
            *q++ = *--bucket;
        }
    }

    // Free memory
    for (int i = 0; i < max_bucket; i++) {
        free(buckets[i]);
    }
    free(buckets);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);

    return 0;
}