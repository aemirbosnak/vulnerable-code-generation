//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUCKETS 1000
#define MAX_RANGE 10000

typedef struct {
    int *data;
    int size;
} Bucket;

void initBucket(Bucket *bucket) {
    bucket->data = malloc(MAX_BUCKETS * sizeof(int));
    bucket->size = 0;
}

void freeBucket(Bucket *bucket) {
    free(bucket->data);
}

void insertBucket(Bucket *bucket, int value) {
    if (bucket->size >= MAX_BUCKETS) {
        printf("Bucket is full\n");
        return;
    }
    bucket->data[bucket->size++] = value;
}

void printBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size; i++) {
        printf("%d ", bucket->data[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    Bucket *bucket = malloc(sizeof(Bucket));
    initBucket(bucket);

    for (int i = 0; i < size; i++) {
        insertBucket(bucket, arr[i]);
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bucket Sort took %lf seconds\n", cpu_time_used);

    freeBucket(bucket);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, size);

    free(arr);
    return 0;
}