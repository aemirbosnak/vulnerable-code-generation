//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int *arr;
int size;

void generateRandomArray(int size) {
    srand(time(NULL));
    arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void printArray(int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int size) {
    int *bucket = (int *) malloc(MAX_SIZE * sizeof(int));
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int bucketSize = range / size;
    for (int i = 0; i < size; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min) / bucketSize;
        bucket[index]++;
    }
    int j = 0;
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < bucket[i]; k++) {
            arr[j++] = i * bucketSize + min + k * bucketSize;
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    generateRandomArray(size);
    printf("Unsorted array:\n");
    printArray(size);
    bucketSort(size);
    printf("Sorted array:\n");
    printArray(size);
    return 0;
}