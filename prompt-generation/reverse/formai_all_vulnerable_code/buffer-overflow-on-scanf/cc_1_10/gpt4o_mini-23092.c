//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

// Structure to manage dynamic array
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function to create a dynamic array
DynamicArray* createArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (!array) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    array->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (!array->data) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(array);
        exit(EXIT_FAILURE);
    }
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
    return array;
}

// Function to resize the dynamic array
void resizeArray(DynamicArray *array) {
    array->capacity *= 2;
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    if (!array->data) {
        fprintf(stderr, "Memory reallocation failed!\n");
        free(array);
        exit(EXIT_FAILURE);
    }
}

// Function to add an element to the array
void addElement(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resizeArray(array);
    }
    array->data[array->size] = value;
    array->size++;
}

// Function to delete an element at a specific index
void deleteElement(DynamicArray *array, size_t index) {
    if (index < array->size) {
        for (size_t i = index; i < array->size - 1; i++) {
            array->data[i] = array->data[i + 1];
        }
        array->size--;
        // Shrink the array if it's too empty
        if (array->size <= array->capacity / 4 && array->capacity > INITIAL_CAPACITY) {
            array->capacity /= 2;
            array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
            if (!array->data) {
                fprintf(stderr, "Memory reallocation failed!\n");
                free(array);
                exit(EXIT_FAILURE);
            }
        }
    } else {
        printf("Index out of bounds!\n");
    }
}

// Function to display the array
void displayArray(DynamicArray *array) {
    if (array->size == 0) {
        printf("Array is empty.\n");
    } else {
        printf("Current Array: ");
        for (size_t i = 0; i < array->size; i++) {
            printf("%d ", array->data[i]);
        }
        printf("\n");
    }
}

// Function to free the array's memory
void freeArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

// Main function to demonstrate dynamic array
int main() {
    DynamicArray *array = createArray();
    int option, value, index;

    do {
        printf("\nDynamic Array Management System\n");
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                addElement(array, value);
                break;
            case 2:
                printf("Enter index to delete: ");
                scanf("%zu", &index);
                deleteElement(array, index);
                break;
            case 3:
                displayArray(array);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (option != 4);

    freeArray(array);
    return 0;
}