//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void displayArray(int *array, int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *dynamicArray = NULL;
    int size = 0;
    int capacity = 2; // Initial capacity setting
    int input;
    char choice;

    // Allocate initial memory for the array
    dynamicArray = (int *)malloc(capacity * sizeof(int));
    if (dynamicArray == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Welcome to Dynamic Array Manipulator!\n");

    do {
        printf("Enter a number to add to the array (or -1 to stop): ");
        scanf("%d", &input);

        if (input == -1) {
            break; // Exit condition
        }

        // Check if we need to expand our array
        if (size >= capacity) {
            capacity *= 2; // Double the capacity
            dynamicArray = (int *)realloc(dynamicArray, capacity * sizeof(int));
            if (dynamicArray == NULL) {
                fprintf(stderr, "Memory reallocation failed!\n");
                return 1;
            }
            printf("Array capacity increased to: %d\n", capacity);
        }

        // Add the new element
        dynamicArray[size] = input;
        size++;
        displayArray(dynamicArray, size);

        printf("Would you like to add another number? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any newline characters
    } while (choice == 'y');

    // Display the final array
    printf("Final Array:\n");
    displayArray(dynamicArray, size);

    // Free allocated memory
    free(dynamicArray);
    dynamicArray = NULL; // Avoid dangling pointer

    printf("Memory deallocated successfully. Exiting program.\n");
    return 0;
}