//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *bucket;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->bucket = (int *)malloc(size * sizeof(int));
    b->size = size;
    memset(b->bucket, 0, size * sizeof(int));
}

void destroyBucket(Bucket *b) {
    free(b->bucket);
}

void insertElement(Bucket *b, int element) {
    int index = element % b->size;
    b->bucket[index]++;
}

void sortBucket(Bucket *b, int *arr, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        insertElement(b, arr[i]);
    }
    for (i = 0; i < b->size; i++) {
        k = 0;
        for (j = 0; j < n; j++) {
            if (arr[j] == i) {
                arr[k++] = arr[j];
            }
        }
    }
}

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n, max, min;
    int *arr;
    Bucket *b;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    createBucket(b, MAX_SIZE);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sortBucket(b, arr, n);
    printArray(arr, n);
    destroyBucket(b);
    free(arr);
    return 0;
}