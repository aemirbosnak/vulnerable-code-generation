//Code Llama-13B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int *data;
} Array;

Array *createArray(int size) {
    Array *arr = malloc(sizeof(Array));
    arr->size = size;
    arr->data = malloc(size * sizeof(int));
    return arr;
}

void printArray(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int *findUniqueElements(Array *arr) {
    int *unique = malloc(arr->size * sizeof(int));
    int uniqueSize = 0;
    for (int i = 0; i < arr->size; i++) {
        int element = arr->data[i];
        int isUnique = 1;
        for (int j = 0; j < i; j++) {
            if (arr->data[j] == element) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            unique[uniqueSize] = element;
            uniqueSize++;
        }
    }
    return unique;
}

void printUniqueElements(int *unique, int uniqueSize) {
    for (int i = 0; i < uniqueSize; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");
}

int main() {
    Array *arr = createArray(10);
    arr->data[0] = 1;
    arr->data[1] = 2;
    arr->data[2] = 3;
    arr->data[3] = 1;
    arr->data[4] = 2;
    arr->data[5] = 4;
    arr->data[6] = 5;
    arr->data[7] = 6;
    arr->data[8] = 7;
    arr->data[9] = 8;

    printArray(arr);

    int *unique = findUniqueElements(arr);
    printUniqueElements(unique, 5);

    free(arr->data);
    free(arr);
    free(unique);

    return 0;
}