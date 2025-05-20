//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].arr = (int *)malloc(MAX_SIZE * sizeof(int));
        buckets[i].size = 0;
    }
}

void deleteBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].arr);
    }
}

void bucketSort(int *arr, int size, int numBuckets) {
    Bucket *buckets = (Bucket *)malloc(numBuckets * sizeof(Bucket));
    createBuckets(buckets, numBuckets);

    int range = MAX_RANGE / numBuckets;

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / range;
        buckets[bucketIndex].arr[buckets[bucketIndex].size++] = arr[i];
    }

    int index = 0;

    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }

    deleteBuckets(buckets, numBuckets);
    free(buckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, size, 10);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}