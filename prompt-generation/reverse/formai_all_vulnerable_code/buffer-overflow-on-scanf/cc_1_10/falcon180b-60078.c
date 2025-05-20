//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->data = (int *)malloc(size * sizeof(int));
    bucket->size = size;
}

void deleteBucket(Bucket *bucket) {
    free(bucket->data);
}

void insertElement(Bucket *bucket, int element) {
    if (bucket->size == 0) {
        createBucket(bucket, MAX_SIZE);
    }
    int i = 0;
    while (i < bucket->size && bucket->data[i] < element) {
        i++;
    }
    bucket->data[i] = element;
    if (i == bucket->size - 1) {
        createBucket(bucket, bucket->size * 2);
        int j = bucket->size - 1;
        while (j > i) {
            bucket->data[j] = bucket->data[j - 1];
            j--;
        }
        bucket->data[i] = element;
    }
}

void bucketSort(Bucket *bucket, int size) {
    int i = 0;
    while (i < size) {
        int element = bucket->data[i];
        insertElement(bucket, element);
        i++;
    }
    int k = 0;
    for (int j = 0; j < size; j++) {
        printf("%d ", bucket->data[j]);
        if (++k == bucket->size) {
            printf("\n");
            k = 0;
        }
    }
}

int main() {
    Bucket bucket;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    createBucket(&bucket, size);
    int i;
    for (i = 0; i < size; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insertElement(&bucket, element);
    }
    printf("Unsorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", bucket.data[i]);
    }
    printf("\n");
    bucketSort(&bucket, size);
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", bucket.data[i]);
    }
    printf("\n");
    deleteBucket(&bucket);
    return 0;
}