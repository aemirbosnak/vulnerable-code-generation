//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void displayArray(int *array, int size) {
    printf("Current elements in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *dynamicArray = NULL; // Pointer to hold the dynamic array
    int size = 0;             // Current size of the array
    int capacity = 2;         // Initial capacity
    int choice, value;

    // Allocate initial memory for the array
    dynamicArray = (int *)malloc(capacity * sizeof(int));
    if (dynamicArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an element\n");
        printf("2. Remove the last element\n");
        printf("3. Display array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add an element
                if (size == capacity) {
                    // Resize the array if needed
                    capacity *= 2;
                    dynamicArray = (int *)realloc(dynamicArray, capacity * sizeof(int));
                    if (dynamicArray == NULL) {
                        fprintf(stderr, "Memory reallocation failed\n");
                        return 1;
                    }
                }
                printf("Enter the value to add: ");
                scanf("%d", &value);
                dynamicArray[size++] = value; // Add the value to the array
                displayArray(dynamicArray, size);
                break;

            case 2: // Remove the last element
                if (size > 0) {
                    size--; // Decrement size to remove the last element
                    printf("Removed last element. ");
                } else {
                    printf("Array is already empty. Cannot remove.\n");
                }
                displayArray(dynamicArray, size);
                break;

            case 3: // Display the array
                displayArray(dynamicArray, size);
                break;

            case 4: // Exit
                free(dynamicArray); // Free the allocated memory
                printf("Exiting the program. Memory freed successfully.\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    return 0;
}