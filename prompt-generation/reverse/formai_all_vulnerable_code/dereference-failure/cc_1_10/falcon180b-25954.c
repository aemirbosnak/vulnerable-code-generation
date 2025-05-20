//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_VALUE 100

typedef struct {
    int size;
    int* data;
} Array;

Array* createArray(int size) {
    Array* arr = (Array*) malloc(sizeof(Array));
    if (arr == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    arr->size = size;
    arr->data = (int*) malloc(sizeof(int) * size);
    if (arr->data == NULL) {
        printf("Failed to allocate memory.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        arr->data[i] = rand() % MAX_VALUE;
    }
    return arr;
}

void printArray(Array* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void freeArray(Array* arr) {
    free(arr->data);
    free(arr);
}

int main() {
    srand(time(NULL));
    Array* arr1 = createArray(MAX_SIZE);
    Array* arr2 = createArray(MAX_SIZE);
    printArray(arr1);
    printArray(arr2);
    Array* sum = createArray(MAX_SIZE);
    for (int i = 0; i < arr1->size; i++) {
        sum->data[i] = arr1->data[i] + arr2->data[i];
    }
    printArray(sum);
    freeArray(arr1);
    freeArray(arr2);
    freeArray(sum);
    return 0;
}