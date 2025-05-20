//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    int *arr;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->size = size;
    bucket->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        bucket->arr[i] = -1;
    }
}

void insertElement(Bucket *bucket, int element) {
    int index = element / 10;
    if (bucket->arr[index] == -1) {
        bucket->arr[index] = element;
        return;
    }
    int *list = (int *)malloc(MAX_SIZE * sizeof(int));
    int count = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bucket->arr[i]!= -1) {
            list[count++] = bucket->arr[i];
        }
    }
    list[count++] = element;
    for (int i = 0; i < MAX_SIZE; i++) {
        bucket->arr[i] = -1;
    }
    for (int i = 0; i < count; i++) {
        int num = list[i];
        int index = num / 10;
        bucket->arr[index] = num;
    }
    free(list);
}

void sortBucket(Bucket *bucket) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bucket->arr[i]!= -1) {
            printf("%d ", bucket->arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    createBucket(bucket, size);
    for (int i = 0; i < size; i++) {
        insertElement(bucket, arr[i]);
    }
    printf("Sorted array:\n");
    sortBucket(bucket);
    return 0;
}