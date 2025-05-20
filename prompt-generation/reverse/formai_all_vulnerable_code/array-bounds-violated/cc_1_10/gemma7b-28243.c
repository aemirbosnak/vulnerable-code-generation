//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_BUCKETS 10
#define BUCKET_SIZE 10

typedef struct bucket {
    int *arr;
    int size;
    struct bucket *next;
} bucket;

bucket *createBucket(int size) {
    bucket *b = malloc(sizeof(bucket));
    b->arr = malloc(size * sizeof(int));
    b->size = size;
    b->next = NULL;
    return b;
}

void insertIntoBucket(bucket *b, int data) {
    if (b->arr == NULL) {
        createBucket(b->size);
    }
    b->arr[b->size++] = data;
}

void bucketSort(int **arr, int n) {
    bucket *buckets[MAX_BUCKETS] = { NULL };
    for (int i = 0; i < n; i++) {
        insertIntoBucket(buckets[*arr[i]], *arr[i]);
    }

    int i = 0;
    for (bucket *b = buckets[0]; b; b = b->next) {
        for (int j = 0; j < b->size; j++) {
            arr[i++] = b->arr[j];
        }
    }
}

int main() {
    int arr[] = { 4, 3, 8, 6, 2, 9, 1, 7, 5, 0 };
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    printf("\n");

    return 0;
}