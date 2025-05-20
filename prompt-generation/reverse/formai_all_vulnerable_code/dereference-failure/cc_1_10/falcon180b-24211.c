//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_ELEMENTS 100

// Define the size of each element in the array
#define ELEMENT_SIZE 10

// Define the structure of an element in the array
typedef struct {
    int value;
    int index;
} Element;

// Define the structure of the array
typedef struct {
    Element *elements;
    int size;
    int capacity;
} Array;

// Function to initialize an array
void array_init(Array *array, int capacity) {
    array->elements = (Element *) malloc(capacity * sizeof(Element));
    array->size = 0;
    array->capacity = capacity;
}

// Function to free an array and its elements
void array_free(Array *array) {
    free(array->elements);
    array->elements = NULL;
    array->size = 0;
    array->capacity = 0;
}

// Function to add an element to the array
void array_add(Array *array, int value) {
    if (array->size >= array->capacity) {
        // Double the capacity of the array
        array->capacity *= 2;
        Element *new_elements = (Element *) realloc(array->elements, array->capacity * sizeof(Element));
        if (new_elements!= NULL) {
            array->elements = new_elements;
        } else {
            printf("Error: Failed to allocate memory for array elements.\n");
            exit(1);
        }
    }
    // Add the new element to the end of the array
    Element *element = &array->elements[array->size];
    element->value = value;
    element->index = array->size;
    array->size++;
}

// Function to remove an element from the array
void array_remove(Array *array, int index) {
    if (index >= array->size) {
        printf("Error: Index out of range.\n");
        return;
    }
    // Move the last element to the position of the removed element
    Element *last_element = &array->elements[array->size - 1];
    Element *element = &array->elements[index];
    last_element->value = element->value;
    last_element->index = element->index;
    // Remove the last element from the array
    array->size--;
}

// Function to search for an element in the array
Element *array_search(Array *array, int value) {
    for (int i = 0; i < array->size; i++) {
        Element *element = &array->elements[i];
        if (element->value == value) {
            return element;
        }
    }
    return NULL;
}

// Function to print the elements of the array
void array_print(Array *array) {
    for (int i = 0; i < array->size; i++) {
        Element *element = &array->elements[i];
        printf("%d (%d)\n", element->value, element->index);
    }
}

int main() {
    // Initialize an array with a capacity of 10 elements
    Array array;
    array_init(&array, 10);

    // Add some elements to the array
    array_add(&array, 1);
    array_add(&array, 2);
    array_add(&array, 3);

    // Print the elements of the array
    array_print(&array);

    // Remove an element from the array
    array_remove(&array, 1);

    // Print the elements of the array again
    array_print(&array);

    // Free the array and its elements
    array_free(&array);

    return 0;
}