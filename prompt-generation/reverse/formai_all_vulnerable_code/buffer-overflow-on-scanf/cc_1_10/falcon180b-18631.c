//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->arr = (int *)malloc(size * sizeof(int));
    bucket->size = size;
}

void destroyBucket(Bucket *bucket) {
    free(bucket->arr);
}

void insertElement(Bucket *bucket, int element) {
    if (bucket->size == 0) {
        createBucket(bucket, 10);
    }
    if (bucket->size == bucket->arr[0]) {
        int *newArr = (int *)malloc(bucket->size * 2 * sizeof(int));
        for (int i = 0; i < bucket->size; i++) {
            newArr[i] = bucket->arr[i];
        }
        free(bucket->arr);
        bucket->arr = newArr;
        bucket->size *= 2;
    }
    int index = element / bucket->size;
    bucket->arr[index] = element;
}

void printBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size; i++) {
        printf("%d ", bucket->arr[i]);
    }
    printf("\n");
}

void bucketSort(Bucket *buckets, int n) {
    int max = buckets[0].arr[0];
    for (int i = 1; i < n; i++) {
        if (buckets[i].arr[0] > max) {
            max = buckets[i].arr[0];
        }
    }
    for (int i = 0; i < n; i++) {
        if (buckets[i].size == 0) {
            continue;
        }
        for (int j = 0; j < buckets[i].size; j++) {
            int element = buckets[i].arr[j];
            int index = element / max;
            insertElement(&buckets[index], element);
        }
    }
    for (int i = 0; i < n; i++) {
        printBucket(&buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        createBucket(&buckets[i], 0);
    }
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insertElement(&buckets[arr[i] / 10], arr[i]);
    }
    bucketSort(buckets, n);
    return 0;
}