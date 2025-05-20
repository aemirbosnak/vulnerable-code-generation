//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_RANGE 100

typedef struct {
    int *arr;
    int size;
} Bucket;

Bucket* createBucket(int size) {
    Bucket *b = (Bucket*)malloc(sizeof(Bucket));
    b->arr = (int*)malloc(sizeof(int) * size);
    b->size = size;
    return b;
}

void freeBucket(Bucket *b) {
    free(b->arr);
    free(b);
}

void insertElement(Bucket *b, int element) {
    int index = element / b->size;
    int offset = element % b->size;
    b->arr[index] = element;
}

void printBucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void sortBucket(Bucket *b) {
    for (int i = 0; i < b->size - 1; i++) {
        for (int j = 0; j < b->size - i - 1; j++) {
            if (b->arr[j] > b->arr[j + 1]) {
                int temp = b->arr[j];
                b->arr[j] = b->arr[j + 1];
                b->arr[j + 1] = temp;
            }
        }
    }
}

void sortArray(int *arr, int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min;
    int numBuckets = range / MAX_RANGE + 1;
    Bucket **buckets = (Bucket**)malloc(sizeof(Bucket*) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = createBucket(MAX_SIZE);
    }
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min) / MAX_RANGE;
        insertElement(buckets[index], arr[i]);
    }
    for (int i = 0; i < numBuckets; i++) {
        sortBucket(buckets[i]);
    }
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
    }
    for (int i = 0; i < numBuckets; i++) {
        freeBucket(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {2, 8, 1, 7, 3, 5, 9, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}