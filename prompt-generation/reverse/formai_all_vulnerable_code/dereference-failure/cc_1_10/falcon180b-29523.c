//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 1000

typedef struct {
    int *data;
    int capacity;
    int size;
} Bucket;

Bucket* createBucket(int capacity) {
    Bucket *b = (Bucket*)malloc(sizeof(Bucket));
    b->data = (int*)malloc(capacity * sizeof(int));
    b->capacity = capacity;
    b->size = 0;
    return b;
}

void deleteBucket(Bucket *b) {
    free(b->data);
    free(b);
}

void insertBucket(Bucket *b, int key) {
    if (b->size >= b->capacity) {
        printf("Bucket overflow\n");
        return;
    }
    b->data[b->size++] = key;
}

void printBucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->data[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int n) {
    Bucket **buckets = (Bucket**)malloc(n * sizeof(Bucket*));
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket(MAX_CAPACITY);
    }

    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int bucketIndex = key / n;
        insertBucket(buckets[bucketIndex], key);
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        Bucket *b = buckets[i];
        while (b->size > 0) {
            arr[j++] = b->data[--b->size];
        }
    }

    for (int i = 0; i < n; i++) {
        deleteBucket(buckets[i]);
    }
    free(buckets);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}