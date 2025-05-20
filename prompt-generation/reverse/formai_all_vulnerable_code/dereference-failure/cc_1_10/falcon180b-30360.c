//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->data = (int *)malloc(size * sizeof(int));
    b->size = size;
    memset(b->data, 0, size * sizeof(int));
}

void insertElement(Bucket *b, int element) {
    int index = element % b->size;
    b->data[index]++;
}

void printBucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->data[i]);
    }
    printf("\n");
}

void mergeBuckets(Bucket *b1, Bucket *b2, Bucket *result) {
    result->size = b1->size + b2->size;
    result->data = (int *)malloc(result->size * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < b1->size && j < b2->size) {
        if (b1->data[i] < b2->data[j]) {
            result->data[k++] = b1->data[i++];
        } else {
            result->data[k++] = b2->data[j++];
        }
    }
    while (i < b1->size) {
        result->data[k++] = b1->data[i++];
    }
    while (j < b2->size) {
        result->data[k++] = b2->data[j++];
    }
}

void bucketSort(int *arr, int size) {
    Bucket *buckets = (Bucket *)malloc(MAX_SIZE * sizeof(Bucket));
    for (int i = 0; i < MAX_SIZE; i++) {
        createBucket(&buckets[i], MAX_SIZE);
    }
    for (int i = 0; i < size; i++) {
        insertElement(&buckets[arr[i] % MAX_SIZE], arr[i]);
    }
    Bucket *result = (Bucket *)malloc(MAX_SIZE * sizeof(Bucket));
    int count = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i].size > 0) {
            mergeBuckets(&buckets[i], &buckets[i], &result[count++]);
        }
    }
    int index = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = result[index++].data[arr[i] % MAX_SIZE];
    }
    free(buckets);
    free(result);
}

int main() {
    int arr[] = { 5, 2, 8, 1, 7, 3, 4, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}