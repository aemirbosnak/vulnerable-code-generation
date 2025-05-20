//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000
#define BUCKET_SIZE 10

int *createArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    return arr;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void bucketSort(int *arr, int size) {
    int *bucket = (int *)malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int index = arr[i] / BUCKET_SIZE;
        bucket[index]++;
    }
    int offset = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        offset += bucket[i];
        bucket[i] = offset;
    }
    int *sortedArr = (int *)malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        int index = arr[i] / BUCKET_SIZE;
        sortedArr[--bucket[index]] = arr[i];
    }
    for (int i = 0; i < size; i++) {
        arr[i] = sortedArr[i];
    }
    free(bucket);
    free(sortedArr);
}

int main() {
    srand(time(NULL));
    int size = MAX_SIZE / 10;
    int *arr = createArray(size);
    printArray(arr, size);
    bucketSort(arr, size);
    printArray(arr, size);
    free(arr);
    return 0;
}