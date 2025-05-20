//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int *createArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
    return arr;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size, int numBuckets) {
    int *buckets = (int *)malloc(numBuckets * sizeof(int));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / (MAX_RANGE / numBuckets);
        buckets[bucketIndex]++;
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * (MAX_RANGE / numBuckets) + j * (MAX_RANGE / numBuckets / buckets[i]);
        }
    }
}

int main() {
    srand(time(NULL));
    int size = MAX_SIZE;
    int numBuckets = 10;

    int *arr = createArray(size);
    printArray(arr, size);

    bucketSort(arr, size, numBuckets);
    printf("Sorted array:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}