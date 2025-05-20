//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to allocate memory for an array
int *allocate_array(int n) {
    if (n <= 0) {
        return NULL;
    }

    // Allocate memory for the array
    int *array = (int *)malloc(sizeof(int) * n);
    if (array == NULL) {
        return NULL;
    }

    // Recursively allocate memory for the remaining elements
    int *remaining = allocate_array(n - 1);
    if (remaining == NULL) {
        free(array);
        return NULL;
    }

    // Return the pointer to the allocated array
    return array;
}

// Recursive function to free memory for an array
void free_array(int *array, int n) {
    if (array == NULL || n <= 0) {
        return;
    }

    // Recursively free memory for the remaining elements
    free_array(array + 1, n - 1);

    // Free memory for the first element
    free(array);
}

int main() {
    // Get the size of the array from the user
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *array = allocate_array(n);
    if (array == NULL) {
        printf("Error allocating memory for the array.\n");
        return EXIT_FAILURE;
    }

    // Initialize the array with values
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Print the array
    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free memory for the array
    free_array(array, n);

    return EXIT_SUCCESS;
}