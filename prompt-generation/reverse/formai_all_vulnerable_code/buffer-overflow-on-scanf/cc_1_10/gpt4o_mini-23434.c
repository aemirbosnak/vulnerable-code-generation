//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputArray(int **array, int *size);
void displayArray(int *array, int size);
int linearSearch(int *array, int size, int value);
void resizeArray(int **array, int *size);
void freeMemory(int *array);

int main() {
    int *array = NULL; // Pointer to dynamically allocated array
    int size = 0;     // Size of the array
    int choice, value, index;

    do {
        printf("\nDynamic Array Search Program\n");
        printf("1. Input Array Elements\n");
        printf("2. Display Array Elements\n");
        printf("3. Search an Element\n");
        printf("4. Resize Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(&array, &size);
                break;
            case 2:
                displayArray(array, size);
                break;
            case 3:
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                index = linearSearch(array, size, value);
                if (index != -1) {
                    printf("Element %d found at index %d.\n", value, index);
                } else {
                    printf("Element %d not found in the array.\n", value);
                }
                break;
            case 4:
                resizeArray(&array, &size);
                break;
            case 0:
                freeMemory(array);
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to input array elements
void inputArray(int **array, int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    
    *array = (int *)malloc((*size) * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    printf("Enter the elements:\n");
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &(*array)[i]);
    }
}

// Function to display array elements
void displayArray(int *array, int size) {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Linear search function
int linearSearch(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return i; // Return the index where the value is found
        }
    }
    return -1; // Value not found
}

// Function to resize the array
void resizeArray(int **array, int *size) {
    int newSize;
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);

    if (newSize <= 0) {
        printf("Invalid size! Please enter a positive integer.\n");
        return;
    }

    *array = (int *)realloc(*array, newSize * sizeof(int));
    if (*array == NULL) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    if (newSize > *size) {
        printf("New elements will be uninitialized. Enter additional values if needed.\n");
        for (int i = *size; i < newSize; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &(*array)[i]);
        }
    }

    *size = newSize; // Update the size
    printf("Array resized to %d elements.\n", *size);
}

// Function to free dynamically allocated memory
void freeMemory(int *array) {
    free(array);
}