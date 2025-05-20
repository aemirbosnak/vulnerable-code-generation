//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory dynamically
void* custom_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory dynamically
void custom_free(void* ptr) {
    free(ptr);
}

// Function to reallocate memory dynamically
void* custom_realloc(void* ptr, size_t new_size) {
    void* new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return new_ptr;
}

// Function to calloc memory dynamically
void* custom_calloc(size_t count, size_t size) {
    void* ptr = calloc(count, size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

int main() {
    // Allocate memory dynamically
    int* ptr1 = (int*)custom_malloc(sizeof(int));
    *ptr1 = 10;
    printf("Value of ptr1: %d\n", *ptr1);

    // Reallocate memory dynamically
    int* ptr2 = (int*)custom_realloc(ptr1, sizeof(int) * 2);
    *ptr2 = 20;
    printf("Value of ptr2: %d\n", *ptr2);

    // Free memory dynamically
    custom_free(ptr1);

    // Allocate memory dynamically
    char** ptr3 = (char**)custom_malloc(sizeof(char*) * 3);
    ptr3[0] = "Hello";
    ptr3[1] = "World";
    ptr3[2] = "Alan";
    printf("Value of ptr3: %s\n", ptr3[0]);

    // Free memory dynamically
    custom_free(ptr3[0]);
    custom_free(ptr3[1]);
    custom_free(ptr3[2]);
    custom_free(ptr3);

    // Allocate memory dynamically
    int*** ptr4 = (int***)custom_calloc(2, sizeof(int**));
    ptr4[0] = (int**)custom_malloc(sizeof(int*) * 2);
    ptr4[0][0] = (int*)custom_malloc(sizeof(int) * 2);
    ptr4[0][0][0] = 1;
    printf("Value of ptr4[0][0][0]: %d\n", ptr4[0][0][0]);

    // Free memory dynamically
    custom_free(ptr4[0][0][0]);
    custom_free(ptr4[0][0]);
    custom_free(ptr4[0]);
    custom_free(ptr4);

    return 0;
}