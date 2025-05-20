//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for each element in the array
typedef struct {
    int value;
    int index;
} Element;

// Define the structure for the array itself
typedef struct {
    Element *elements;
    int size;
} Array;

// Function to initialize the array
void initArray(Array *array) {
    array->elements = (Element *)malloc(MAX_SIZE * sizeof(Element));
    array->size = 0;
}

// Function to add an element to the array
void addElement(Array *array, int value) {
    if (array->size == MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }
    array->elements[array->size].value = value;
    array->elements[array->size].index = array->size;
    array->size++;
}

// Function to remove an element from the array
void removeElement(Array *array, int index) {
    if (index >= array->size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->elements[i].index = i;
        array->elements[i].value = array->elements[i + 1].value;
    }
    array->size--;
}

// Function to search for an element in the array
int searchElement(Array *array, int value) {
    for (int i = 0; i < array->size; i++) {
        if (array->elements[i].value == value) {
            return array->elements[i].index;
        }
    }
    return -1;
}

// Function to print the array
void printArray(Array *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d: %d\n", array->elements[i].index, array->elements[i].value);
    }
}

int main() {
    // Initialize the array
    Array array;
    initArray(&array);

    // Add some elements to the array
    addElement(&array, 10);
    addElement(&array, 20);
    addElement(&array, 30);

    // Print the array
    printArray(&array);

    // Remove an element from the array
    removeElement(&array, 1);

    // Print the array again
    printArray(&array);

    // Search for an element in the array
    int index = searchElement(&array, 20);
    if (index!= -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}