//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int *array;
    int size;
} Bucket;

Bucket *createBucket(int size) {
    Bucket *b = (Bucket *)malloc(sizeof(Bucket));
    b->array = (int *)malloc(sizeof(int) * size);
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->array[i] = -1;
    }
    return b;
}

void insertBucket(Bucket *b, int val) {
    int index = abs(val) % b->size;
    if (b->array[index] == -1) {
        b->array[index] = val;
    } else {
        printf("Error: Duplicate value found!\n");
    }
}

void printBucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        if (b->array[i]!= -1) {
            printf("%d ", b->array[i]);
        }
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    Bucket *b = createBucket(MAX_SIZE);
    for (int i = 0; i < n; i++) {
        insertBucket(b, arr[i]);
    }
    int count = 0;
    for (int i = 0; i < b->size; i++) {
        if (b->array[i]!= -1) {
            arr[count++] = b->array[i];
        }
    }
}

int main() {
    int arr[] = { -3, 5, 2, -8, 1, 6, 0, -4, 7, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}