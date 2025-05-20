//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

typedef struct {
    int *data;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->data = malloc(size * sizeof(int));
    bucket->size = size;
}

void deleteBucket(Bucket *bucket) {
    free(bucket->data);
}

void distribute(int *data, int size, int numBuckets) {
    int range = size / numBuckets;
    for (int i = 0; i < size; i++) {
        int bucketIndex = data[i] / range;
        int indexInBucket = data[i] % range;
        int *bucket = &data[bucketIndex * range];
        bucket[indexInBucket] = data[i];
    }
}

void sortBucket(int *data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void mergeBuckets(int *data, int numBuckets, int size) {
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        int bucketIndex = i * size / numBuckets;
        int bucketSize = size / numBuckets;
        for (int j = 0; j < bucketSize; j++) {
            data[index] = data[bucketIndex + j];
            index++;
        }
    }
}

void bucketSort(int *data, int size) {
    int numBuckets = 10;
    Bucket *buckets = malloc(numBuckets * sizeof(Bucket));
    for (int i = 0; i < numBuckets; i++) {
        createBucket(&buckets[i], size / numBuckets);
    }
    distribute(data, size, numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        sortBucket(buckets[i].data, buckets[i].size);
    }
    mergeBuckets(data, numBuckets, size);
    for (int i = 0; i < numBuckets; i++) {
        deleteBucket(&buckets[i]);
    }
    free(buckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *data = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100000;
    }
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    clock_t start = clock();
    bucketSort(data, size);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Time taken: %lf seconds\n", timeTaken);
    return 0;
}