//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

Bucket *createBucket(int size) {
    Bucket *b = (Bucket *)malloc(sizeof(Bucket));
    b->arr = (int *)malloc((size + 1) * sizeof(int));
    b->size = size;
    for (int i = 0; i <= size; i++) {
        b->arr[i] = 0;
    }
    return b;
}

void insertElement(Bucket *b, int element) {
    int index = element / b->size;
    b->arr[index]++;
}

void sortBucket(Bucket *b) {
    for (int i = 1; i <= b->size; i++) {
        b->arr[i] += b->arr[i - 1];
    }
}

void printBucket(Bucket *b) {
    for (int i = 0; i <= b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    Bucket *b = createBucket(size);
    for (int i = 0; i < size; i++) {
        insertElement(b, arr[i]);
    }
    sortBucket(b);
    int index = 0;
    for (int i = 0; i <= b->size; i++) {
        for (int j = 0; j < b->arr[i]; j++) {
            arr[index++] = i * b->size + j;
        }
    }
}

int main() {
    int arr[] = { 3, 7, 1, 9, 2, 5, 8, 4, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}