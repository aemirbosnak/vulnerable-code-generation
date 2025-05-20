//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 100

typedef struct {
    int *data;
    int size;
} IntArray;

void initArray(IntArray *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
    for (int i = 0; i < size; i++) {
        array->data[i] = rand() % MAX_VALUE;
    }
}

void printArray(IntArray array) {
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.data[i]);
    }
    printf("\n");
}

int binarySearch(IntArray array, int target) {
    int left = 0;
    int right = array.size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (array.data[mid] == target) {
            return mid;
        } else if (array.data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    IntArray array;
    initArray(&array, MAX_SIZE);
    printArray(array);

    int target = rand() % MAX_VALUE;
    int result = binarySearch(array, target);

    if (result!= -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("Not found\n");
    }

    return 0;
}