//Falcon-180B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    char *data;
} DynamicArray;

DynamicArray *createDynamicArray(int size) {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }
    array->size = size;
    array->data = (char *) malloc(size * sizeof(char));
    if (array->data == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }
    memset(array->data, '\0', size * sizeof(char));
    return array;
}

void append(DynamicArray *array, char *str) {
    int len = strlen(str);
    if (array->size - strlen(array->data) < len) {
        int newSize = array->size + MAX_SIZE;
        char *newData = (char *) realloc(array->data, newSize * sizeof(char));
        if (newData == NULL) {
            printf("Error: Failed to reallocate memory.\n");
            exit(1);
        }
        array->data = newData;
        array->size = newSize;
    }
    strcat(array->data, str);
}

void printDynamicArray(DynamicArray *array) {
    printf("%s\n", array->data);
}

int main() {
    DynamicArray *array = createDynamicArray(10);
    append(array, "Hello");
    append(array, " World!");
    printDynamicArray(array);
    free(array->data);
    free(array);
    return 0;
}