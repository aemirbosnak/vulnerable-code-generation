//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBuckets(Bucket *buckets, int numBuckets, int maxVal) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].arr = (int *) malloc(sizeof(int) * maxVal);
        buckets[i].size = 0;
    }
}

void destroyBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].arr);
    }
}

void insertElement(Bucket *buckets, int numBuckets, int val) {
    int bucketIndex = val % numBuckets;
    buckets[bucketIndex].arr[buckets[bucketIndex].size++] = val;
}

void printBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size; i++) {
        printf("%d ", bucket->arr[i]);
    }
    printf("\n");
}

void printBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        printBucket(buckets + i);
    }
}

void mergeBuckets(Bucket *buckets, int numBuckets, int *arr, int start, int end) {
    int i = start;
    for (int j = 0; j < numBuckets; j++) {
        while (i < end && buckets[j].arr[buckets[j].size - 1] <= arr[i]) {
            i++;
        }
        if (i < end) {
            arr[i] = buckets[j].arr[--buckets[j].size];
        }
    }
}

void bucketSort(int *arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    Bucket *buckets = (Bucket *) malloc(sizeof(Bucket) * maxVal + 1);
    createBuckets(buckets, maxVal + 1, maxVal);

    for (int i = 0; i < size; i++) {
        insertElement(buckets, maxVal + 1, arr[i]);
    }

    int *sortedArr = (int *) malloc(sizeof(int) * size);
    int sortedSize = 0;

    for (int i = maxVal; i >= 1; i--) {
        mergeBuckets(buckets, maxVal + 1, sortedArr, sortedSize, size - 1);
        sortedSize += buckets[i].size;
        buckets[i].size = 0;
    }

    free(buckets);
    printf("Sorted array:\n");
    printBuckets(buckets, maxVal + 1);
}

int main() {
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 1;
    int *arr = (int *) malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    printf("Unsorted array:\n");
    printBuckets(arr, size);

    bucketSort(arr, size);

    free(arr);
    return 0;
}