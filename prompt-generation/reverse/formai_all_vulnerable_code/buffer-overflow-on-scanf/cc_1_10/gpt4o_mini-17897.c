//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function to initialize the dynamic array
DynamicArray* create_array(size_t initial_capacity) {
    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (array == NULL) {
        perror("Failed to allocate memory for dynamic array");
        exit(EXIT_FAILURE);
    }
    
    array->data = (int*)malloc(initial_capacity * sizeof(int));
    if (array->data == NULL) {
        perror("Failed to allocate memory for array data");
        free(array);
        exit(EXIT_FAILURE);
    }
    
    array->size = 0;
    array->capacity = initial_capacity;
    return array;
}

// Function to resize the array when it's full
void resize_array(DynamicArray* array) {
    size_t new_capacity = array->capacity * 2;
    int* new_data = (int*)realloc(array->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        perror("Failed to reallocate memory for array data");
        free(array->data);
        free(array);
        exit(EXIT_FAILURE);
    }
    
    array->data = new_data;
    array->capacity = new_capacity;
}

// Function to add an element to the array
void add_element(DynamicArray* array, int element) {
    if (array->size >= array->capacity) {
        resize_array(array);
    }
    array->data[array->size++] = element;
}

// Function to free the dynamic array
void free_array(DynamicArray* array) {
    free(array->data);
    free(array);
}

// Function to print the array elements
void print_array(DynamicArray* array) {
    printf("Array elements: ");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    size_t initial_capacity;
    printf("Enter initial capacity for the dynamic array: ");
    scanf("%zu", &initial_capacity);
    
    DynamicArray* myArray = create_array(initial_capacity);
    
    char option;
    do {
        printf("Enter a number to add to the array (or 'q' to quit): ");
        if (scanf(" %c", &option) && option == 'q') {
            break;
        }
        
        ungetc(option, stdin); // Pushback the character back to input
        int number;
        if (scanf("%d", &number) == 1) {
            add_element(myArray, number);
        } else {
            printf("Invalid input, please enter an integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
        
        print_array(myArray);
    } while (option != 'q');
    
    free_array(myArray);
    return 0;
}