//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int main() {
    int i, n;
    int *arr;
    double start_time, end_time;
    int count = 0;

    // Allocate memory for the array
    arr = (int*)malloc(MAX_SIZE * sizeof(int));

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Print unsorted array
    printf("Unsorted Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bucket Sort Algorithm
    start_time = clock();
    for (i = 0; i < MAX_SIZE; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    int *bucket = (int*)malloc(count * sizeof(int));
    for (i = 0; i < MAX_SIZE; i++) {
        if (arr[i] < 0) {
            bucket[count - 1] = arr[i];
            count--;
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (arr[i] >= 0) {
            bucket[count++] = arr[i];
        }
    }
    count = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = bucket[count++];
    }
    end_time = clock();
    printf("Sorted Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);
    free(bucket);

    return 0;
}