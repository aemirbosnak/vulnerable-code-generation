//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* data;
    int size;
} Array;

void createArray(Array* arr) {
    arr->data = (char*)malloc(MAX_SIZE * sizeof(char));
    arr->size = 0;
}

void addElement(Array* arr, char* element) {
    if (arr->size >= MAX_SIZE) {
        printf("Array is full. Cannot add element.\n");
        return;
    }
    strcpy(arr->data + arr->size, element);
    arr->size += strlen(element) + 1; // +1 for null terminator
}

int searchElement(Array* arr, char* element) {
    int i = 0;
    while (i < arr->size) {
        if (strcmp(arr->data + i, element) == 0) {
            return i;
        }
        i++;
    }
    return -1; // element not found
}

int main() {
    Array arr;
    createArray(&arr);

    addElement(&arr, "apple");
    addElement(&arr, "banana");
    addElement(&arr, "cherry");
    addElement(&arr, "date");

    int index = searchElement(&arr, "banana");
    if (index!= -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    free(arr.data);
    return 0;
}