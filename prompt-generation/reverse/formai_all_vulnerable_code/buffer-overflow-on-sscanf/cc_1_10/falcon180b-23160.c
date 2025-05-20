//Falcon-180B DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int *array;
    int capacity;
    int size;
} IntArray;

IntArray createIntArray(int capacity) {
    IntArray result = {
       .array = malloc(capacity * sizeof(int)),
       .capacity = capacity,
       .size = 0
    };

    if (result.array == NULL) {
        printf("Error: Failed to allocate memory for array\n");
        exit(1);
    }

    return result;
}

void destroyIntArray(IntArray *array) {
    free(array->array);
}

void addIntToArray(IntArray *array, int value) {
    if (array->size == array->capacity) {
        printf("Error: Array is full\n");
        exit(1);
    }

    array->array[array->size++] = value;
}

int main() {
    char line[MAX_LINE_LENGTH];
    IntArray array = createIntArray(10);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int value;
        if (sscanf(line, "%d", &value)!= 1) {
            printf("Error: Invalid input\n");
            exit(1);
        }

        addIntToArray(&array, value);
    }

    printf("Array contains %d elements:\n", array.size);
    for (int i = 0; i < array.size; i++) {
        printf("%d ", array.array[i]);
    }

    destroyIntArray(&array);
    return 0;
}