//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void displayArray(int *arr, int size) {
    if (size == 0) {
        printf("Array is currently empty!\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to add an element to the array
int *addElement(int *arr, int *size, int value) {
    // Increase size by 1
    *size += 1;
    // Allocate new memory
    arr = realloc(arr, (*size) * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    arr[*size - 1] = value; // Add new element
    printf("Added %d to the array!\n", value);
    return arr;
}

// Function to remove an element from the array
int *removeElement(int *arr, int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return arr;
    }
    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    *size -= 1;
    arr = realloc(arr, (*size) * sizeof(int));
    if (arr == NULL && *size > 0) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("Removed element at position %d!\n", position);
    return arr;
}

int main() {
    int *arr = NULL; // Pointer to hold the array
    int size = 0;   // Current size of the array
    int choice, value, position;

    do {
        printf("\nDynamic Array Management Menu:\n");
        printf("1. Add Element\n");
        printf("2. Remove Element\n");
        printf("3. View Array\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                arr = addElement(arr, &size, value);
                break;
            case 2:
                printf("Enter the position to remove (0 to %d): ", size - 1);
                scanf("%d", &position);
                arr = removeElement(arr, &size, position);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Free allocated memory
    free(arr);
    printf("All allocated memory freed! Goodbye!\n");

    return 0;
}