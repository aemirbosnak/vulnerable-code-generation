//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 4
#define GROWTH_FACTOR 2

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// Function prototypes
DynamicArray* create_array();
void destroy_array(DynamicArray *array);
void add_element(DynamicArray *array, int element);
void remove_element(DynamicArray *array);
void display_array(DynamicArray *array);
void resize_array(DynamicArray *array, size_t new_capacity);

int main() {
    DynamicArray *array = create_array();
    int choice, value;

    while (1) {
        printf("\nDynamic Array Menu:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. Display Elements\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to add: ");
                scanf("%d", &value);
                add_element(array, value);
                break;
            case 2:
                remove_element(array);
                break;
            case 3:
                display_array(array);
                break;
            case 4:
                destroy_array(array);
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

DynamicArray* create_array() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (!array) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    array->data = (int *)malloc(INITIAL_SIZE * sizeof(int));
    if (!array->data) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(array);
        exit(EXIT_FAILURE);
    }
    
    array->size = 0;
    array->capacity = INITIAL_SIZE;
    return array;
}

void destroy_array(DynamicArray *array) {
    if (array) {
        free(array->data);
        free(array);
    }
}

void add_element(DynamicArray *array, int element) {
    if (array->size >= array->capacity) {
        resize_array(array, array->capacity * GROWTH_FACTOR);
    }
    array->data[array->size++] = element;
    printf("Element added: %d\n", element);
}

void remove_element(DynamicArray *array) {
    if (array->size > 0) {
        int removed_element = array->data[--array->size];
        printf("Element removed: %d\n", removed_element);
    } else {
        printf("Array is empty! Cannot remove element.\n");
    }
}

void resize_array(DynamicArray *array, size_t new_capacity) {
    int *new_data = (int *)realloc(array->data, new_capacity * sizeof(int));
    if (!new_data) {
        fprintf(stderr, "Memory reallocation failed!\n");
        destroy_array(array);
        exit(EXIT_FAILURE);
    }
    array->data = new_data;
    array->capacity = new_capacity;
    printf("Array resized to capacity: %zu\n", new_capacity);
}

void display_array(DynamicArray *array) {
    if (array->size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Current elements in array: ");
    for (size_t i = 0; i < array->size; ++i) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}