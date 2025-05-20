//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *b) {
    b->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    b->size = 0;
}

void insertElement(Bucket *b, int element) {
    if (b->size == MAX_SIZE) {
        printf("Bucket is full!\n");
        return;
    }
    b->arr[b->size++] = element;
}

void printBucket(Bucket b) {
    printf("Bucket: ");
    for (int i = 0; i < b.size; i++) {
        printf("%d ", b.arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    Bucket buckets[n];
    for (int i = 0; i < n; i++) {
        createBucket(&buckets[i]);
    }

    for (int i = 0; i < n; i++) {
        int element = arr[i];
        int index = element * n / (MAX_SIZE * 2);
        insertElement(&buckets[index], element);
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < buckets[i].size) {
            arr[i] = buckets[i].arr[j++];
        }
    }
}

int main() {
    int arr[] = {34, 12, 89, 5, 67, 23, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}