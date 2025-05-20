//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;        // Pointer to dynamically allocate integer array
    size_t capacity;  // Total capacity of the array
    size_t size;      // Current size of the array
} DynamicArray;

// Function prototypes
DynamicArray* create_array(size_t initial_capacity);
void add_element(DynamicArray *array, int element);
void print_array(const DynamicArray *array);
void free_array(DynamicArray *array);

int main() {
    size_t initial_capacity = 4; // Initial capacity for the dynamic array
    DynamicArray *myArray = create_array(initial_capacity);
    
    if (myArray == NULL) {
        printf("Failed to create array!\n");
        return 1;
    }

    int choice, value;

    while (1) {
        printf("\n1. Add Element\n2. Print Array\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer value to add: ");
                scanf("%d", &value);
                add_element(myArray, value);
                break;
            case 2:
                print_array(myArray);
                break;
            case 3:
                free_array(myArray);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a dynamic array
DynamicArray* create_array(size_t initial_capacity) {
    DynamicArray *array = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (array == NULL) 
        return NULL; // Return NULL if memory allocation fails
    
    array->data = (int*) malloc(initial_capacity * sizeof(int));
    if (array->data == NULL) {
        free(array); // Release any allocated memory
        return NULL;
    }

    array->capacity = initial_capacity;
    array->size = 0;
    return array;
}

// Function to add an element to the dynamic array
void add_element(DynamicArray *array, int element) {
    if (array->size >= array->capacity) {
        // Resize the array if necessary
        size_t new_capacity = array->capacity * 2;
        int *new_data = (int*) realloc(array->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            printf("Failed to resize array! Element not added.\n");
            return;
        }
        array->data = new_data;
        array->capacity = new_capacity; // Update the new capacity
    }
    array->data[array->size++] = element; // Add the new element and increment size
}

// Function to print the contents of the dynamic array
void print_array(const DynamicArray *array) {
    printf("Array Contents: ");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// Function to free the memory allocated for the dynamic array
void free_array(DynamicArray *array) {
    if (array != NULL) {
        free(array->data); // Free the data array
        free(array);       // Free the struct itself
    }
}