//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *b) {
    b->arr = (int *) malloc(MAX_SIZE * sizeof(int));
    b->size = 0;
}

void destroyBucket(Bucket *b) {
    free(b->arr);
    b->arr = NULL;
    b->size = 0;
}

void insertBucket(Bucket *b, int num) {
    if (b->size == MAX_SIZE) {
        printf("Bucket is full\n");
        return;
    }

    b->arr[b->size++] = num;
}

void bucketSort(int arr[], int size) {
    Bucket buckets[10]; // create 10 buckets
    int i, j, n;
    for (i = 0; i < 10; i++) {
        createBucket(&buckets[i]);
    }

    for (i = 0; i < size; i++) {
        n = arr[i] * 10; // determine which bucket to insert the element
        insertBucket(&buckets[n], arr[i]);
    }

    int index = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }

    for (i = 0; i < 10; i++) {
        destroyBucket(&buckets[i]);
    }
}

int main() {
    int arr[] = { 23, 45, 67, 12, 89, 34, 56, 78 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}