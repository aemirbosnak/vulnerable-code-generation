//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define RANGE 10000

typedef struct bucket {
    int *array;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->array = (int *)malloc(size * sizeof(int));
    b->size = size;
}

void destroyBucket(Bucket *b) {
    free(b->array);
}

void initArray(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size, int numBuckets) {
    Bucket *buckets = (Bucket *)malloc(numBuckets * sizeof(Bucket));

    int bucketSize = size / numBuckets;

    for (int i = 0; i < numBuckets; i++) {
        createBucket(&buckets[i], bucketSize);
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / RANGE;
        int indexInBucket = arr[i] % RANGE;

        if (indexInBucket == 0) {
            indexInBucket = RANGE;
        }

        buckets[bucketIndex].array[indexInBucket - 1] = arr[i];
    }

    int index = 0;

    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].array[j];
        }
    }

    for (int i = 0; i < numBuckets; i++) {
        destroyBucket(&buckets[i]);
    }

    free(buckets);
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    initArray(arr, size);
    printArray(arr, size);

    bucketSort(arr, size, 10);

    printArray(arr, size);

    free(arr);

    return 0;
}