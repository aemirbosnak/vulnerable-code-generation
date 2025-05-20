//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int *create_array(size_t size) {
    if (size > MAX_ARRAY_SIZE) {
        handle_error("Requested array size exceeds maximum allowed size.");
    }
    
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        handle_error("Memory allocation failed.");
    }
    
    return array;
}

void fill_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Enter value for element %zu: ", i);
        if (scanf("%d", &array[i]) != 1) {
            handle_error("Invalid input! Please enter an integer.");
        }
    }
}

void print_array(int *array, size_t size) {
    printf("The contents of the array are:\n");
    for (size_t i = 0; i < size; i++) {
        printf("Element %zu: %d\n", i, array[i]);
    }
}

void free_array(int *array) {
    free(array);
}

int main() {
    size_t array_size;
    
    printf("Enter the size of the array (max %d): ", MAX_ARRAY_SIZE);
    if (scanf("%zu", &array_size) != 1) {
        handle_error("Invalid input! Please enter an integer for array size.");
    }
    
    int *array = create_array(array_size);
    
    fill_array(array, array_size);
    
    print_array(array, array_size);
    
    free_array(array);
    
    return 0;
}