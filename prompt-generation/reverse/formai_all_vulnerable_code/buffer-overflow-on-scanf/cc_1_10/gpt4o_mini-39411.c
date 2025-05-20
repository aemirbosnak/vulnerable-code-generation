//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function to initialize a DynamicArray
DynamicArray *initArray(size_t initialCapacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    arr->data = malloc(initialCapacity * sizeof(int));
    if (!arr->data) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(arr);
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

// Function to free the DynamicArray
void freeArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}

// Function to add an element to the DynamicArray
void append(DynamicArray *arr, int value) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        if (!arr->data) {
            fprintf(stderr, "Memory reallocation failed!\n");
            freeArray(arr);
            exit(EXIT_FAILURE);
        }
    }
    arr->data[arr->size++] = value;
}

// Function to remove an element from the DynamicArray
void removeAt(DynamicArray *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds!\n");
        return;
    }
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Function to display the elements in the DynamicArray
void displayArray(const DynamicArray *arr) {
    printf("Dynamic Array: ");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Program main
int main() {
    DynamicArray *arr = initArray(4); // Start with an initial capacity of 4
    
    // Menu for user interaction
    int choice, value, index;
    while (1) {
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to add: ");
                scanf("%d", &value);
                append(arr, value);
                break;
            case 2:
                printf("Enter index of the element to remove: ");
                scanf("%d", &index);
                removeAt(arr, index);
                break;
            case 3:
                displayArray(arr);
                break;
            case 4:
                freeArray(arr);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}