//FormAI DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Shape-Shifting Memory Management program!\n\n");

    // Request user input for the desired size of the array
    int size;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate an array of integers with the user-specified size
    int* arr = (int*)malloc(size * sizeof(int));
    printf("Successfully allocated memory for an array of %d integers!\n\n", size);

    // Randomly populate the array with integers from 0 to 99
    printf("Populating the array with random integers...\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    printf("Array populated!\n\n");

    // Print out the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Request user input for the new desired size of the array
    int new_size;
    printf("Please enter the new size of the array: ");
    scanf("%d", &new_size);

    // Reallocate the array with the new user-specified size
    int* new_arr = (int*)realloc(arr, new_size * sizeof(int));
    if (new_arr == NULL) {
        printf("Unable to reallocate memory for the new array of size %d!\n", new_size);
        return 0;
    }
    printf("Successfully reallocated memory for a new array of size %d!\n\n", new_size);

    // Randomly populate the new array with integers from 0 to 99
    printf("Populating the new array with random integers...\n");
    for (int i = size; i < new_size; i++) {
        new_arr[i] = rand() % 100;
    }
    printf("New array populated!\n\n");

    // Print out the new array
    printf("New array: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n\n");

    // Deallocate the memory for the arrays
    free(new_arr);
    printf("Memory deallocated!\n");

    return 0;
}