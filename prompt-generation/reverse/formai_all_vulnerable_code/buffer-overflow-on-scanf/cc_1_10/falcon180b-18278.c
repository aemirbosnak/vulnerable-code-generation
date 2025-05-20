//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
}

void destroyBucket(Bucket *b) {
    free(b->arr);
}

void insert(Bucket *b, int val) {
    int i = 0;
    while (i < b->size && val > b->arr[i]) {
        i++;
    }
    for (int j = b->size - 1; j > i; j--) {
        b->arr[j] = b->arr[j - 1];
    }
    b->arr[i] = val;
}

void printBucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    Bucket *b = (Bucket *)malloc(size * sizeof(Bucket));
    for (int i = 0; i < size; i++) {
        createBucket(&b[i], size);
    }

    for (int i = 0; i < size; i++) {
        int val = arr[i];
        int bucketIndex = val % size;
        insert(&b[bucketIndex], val);
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        Bucket *bucket = &b[i];
        while (bucket->size > 0) {
            arr[index++] = bucket->arr[--bucket->size];
        }
    }

    for (int i = 0; i < size; i++) {
        destroyBucket(&b[i]);
    }
    free(b);
}

int main() {
    int arr[MAX];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int randIndex = rand() % size;
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}