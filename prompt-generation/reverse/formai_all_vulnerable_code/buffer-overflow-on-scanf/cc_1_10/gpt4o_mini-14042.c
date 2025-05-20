//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void allocateAndFill(int **array, int size);
void displayArray(int *array, int size);
void freeMemory(int *array);
int getSizeFromUser();

// Main function
int main() {
    // Start with a curious mind about memory management
    printf("Welcome to the Memory Management Exploration Program!\n");
    printf("Let's dynamically allocate memory for an array of integers.\n");

    // Get size of the array from the user
    int size = getSizeFromUser();

    // Dynamic memory allocation
    int *array = NULL;
    allocateAndFill(&array, size);

    // Display the populated array
    displayArray(array, size);

    // Free allocated memory
    freeMemory(array);

    printf("Memory has been successfully freed. Goodbye!\n");
    return 0;
}

// Function to allocate memory and fill the array
void allocateAndFill(int **array, int size) {
    // Allocating memory for an integer array of given size
    *array = (int *)malloc(size * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    // Filling the array with values
    for (int i = 0; i < size; i++) {
        (*array)[i] = i + 1; // Filling with 1, 2, ..., size
    }
    printf("Memory allocated and array filled successfully.\n");
}

// Function to display the array contents
void displayArray(int *array, int size) {
    printf("Here are the values in your array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, array[i]);
    }
}

// Function to free allocated memory
void freeMemory(int *array) {
    if (array != NULL) {
        free(array);
        printf("Memory freed.\n");
    } else {
        printf("No memory to free.\n");
    }
}

// Function to get size input from user
int getSizeFromUser() {
    int size;
    printf("Please enter the size of the array you want to create: ");
    while (scanf("%d", &size) != 1 || size <= 0) {
        while(getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Please enter a positive integer: ");
    }
    return size;
}