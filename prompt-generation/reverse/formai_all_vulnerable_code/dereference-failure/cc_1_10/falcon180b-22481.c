//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int size;
    char **data;
} Array;

void init(Array *array) {
    array->size = 0;
    array->data = (char **)malloc(MAX_SIZE * sizeof(char *));
}

void add(Array *array, char *value) {
    if (array->size >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    array->data[array->size] = strdup(value);
    array->size++;
}

int search(Array array, char *value) {
    int i;
    for (i = 0; i < array.size; i++) {
        if (strcmp(array.data[i], value) == 0) {
            return i;
        }
    }
    return -1;
}

void print(Array array) {
    int i;
    for (i = 0; i < array.size; i++) {
        printf("%s\n", array.data[i]);
    }
}

int main() {
    Array array;
    init(&array);
    add(&array, "apple");
    add(&array, "banana");
    add(&array, "cherry");
    print(array);
    int index = search(array, "banana");
    if (index!= -1) {
        printf("Found %s at index %d\n", array.data[index], index);
    } else {
        printf("Not found\n");
    }
    free(array.data);
    return 0;
}