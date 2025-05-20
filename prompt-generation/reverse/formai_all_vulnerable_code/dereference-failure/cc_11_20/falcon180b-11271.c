//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int n, i, j, k, max, min, range, bucket_size;
    int *arr, *bucket;
    clock_t start, end;
    double cpu_time_used;

    // Generate random array
    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;
    arr = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Find min and max values in array
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate range and bucket size
    range = max - min + 1;
    bucket_size = range / n;

    // Create buckets
    bucket = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucket_size;
        bucket[j]++;
    }

    // Sort buckets
    for (i = 0; i < n; i++) {
        k = 0;
        for (j = 0; j < n; j++) {
            if (bucket[j] > 0) {
                if (k >= i) {
                    arr[k] = j * bucket_size + min;
                    k++;
                }
                bucket[j]--;
            }
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);
    free(bucket);

    return 0;
}