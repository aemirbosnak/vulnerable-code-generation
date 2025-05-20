//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_SIZE 10

// Function prototypes
void printMenu();
void allocateArray(int **arr, int size);
void freeArray(int *arr);
void inputArray(int *arr, int size);
void printArray(int *arr, int size);
void accessElement(int *arr, int size);
void addElement(int *arr, int *size);
void deleteElement(int *arr, int *size);

// Main function
int main() {
    int *arr = NULL;
    int size = 0, choice;

    // Allocate initial memory for array
    allocateArray(&arr, MAX_SIZE);
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    do {
        // Print menu and get user choice
        printMenu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                inputArray(arr, size);
                break;
            case 2:
                printArray(arr, size);
                break;
            case 3:
                accessElement(arr, size);
                break;
            case 4:
                addElement(arr, &size);
                break;
            case 5:
                deleteElement(arr, &size);
                break;
            case 6:
                freeArray(arr);
                printf("Exiting program.\n");
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "Error: Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 6);

    freeArray(arr);
    return EXIT_SUCCESS;
}

// Function to print the menu
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Input Array Elements\n");
    printf("2. Print Array Elements\n");
    printf("3. Access an Element\n");
    printf("4. Add an Element\n");
    printf("5. Delete an Element\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to allocate memory for the array
void allocateArray(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in allocateArray.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to free the allocated memory
void freeArray(int *arr) {
    free(arr);
}

// Function to input array elements
void inputArray(int *arr, int size) {
    printf("Enter %d elements:\n", MAX_SIZE);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
            while(getchar() != '\n'); // Clear the input buffer
            i--; // Decrement i to retry this index
        }
    }
    printf("Array elements entered successfully.\n");
}

// Function to print array elements
void printArray(int *arr, int size) {
    printf("Array Elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to access an element by index
void accessElement(int *arr, int size) {
    int index;
    printf("Enter index to access (0 to %d): ", size - 1);
    
    if (scanf("%d", &index) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        while(getchar() != '\n'); // Clear the input buffer
        return;
    }

    if (index < 0 || index >= size) {
        fprintf(stderr, "Error: Index out of bounds.\n");
    } else {
        printf("Element at index %d: %d\n", index, arr[index]);
    }
}

// Function to add an element to the array
void addElement(int *arr, int *size) {
    if (*size >= MAX_SIZE) {
        fprintf(stderr, "Error: Array is full. Cannot add more elements.\n");
        return;
    }

    int element;
    printf("Enter element to add: ");
    if (scanf("%d", &element) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        while(getchar() != '\n'); // Clear the input buffer
        return;
    }

    arr[*size] = element;
    (*size)++;
    printf("Element added successfully.\n");
}

// Function to delete the last element from the array
void deleteElement(int *arr, int *size) {
    if (*size <= 0) {
        fprintf(stderr, "Error: Array is empty. Cannot delete any element.\n");
    } else {
        (*size)--;
        printf("Element deleted successfully. New size: %d\n", *size);
    }
}