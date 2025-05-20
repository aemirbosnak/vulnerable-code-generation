//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

int main() {
    int i, n, max, min, range, size;
    int *array, *bucket;
    double elapsed_time;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &n);

    // Generate random array
    srand(time(NULL));
    array = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        array[i] = rand() % MAX_SIZE;
    }

    // Sort array using bucket sort
    max = array[0];
    min = array[0];
    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }
    range = max - min + 1;
    size = ceil((double)n / range);
    bucket = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[array[i] / BUCKET_SIZE]++;
    }
    for (i = 1; i < size; i++) {
        bucket[i] += bucket[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        bucket[array[i] / BUCKET_SIZE]--;
        array[bucket[array[i] / BUCKET_SIZE] - 1] = array[i];
    }

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free memory
    free(array);
    free(bucket);

    return 0;
}