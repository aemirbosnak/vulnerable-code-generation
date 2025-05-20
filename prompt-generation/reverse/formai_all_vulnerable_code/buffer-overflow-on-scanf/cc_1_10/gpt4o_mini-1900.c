//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function prototypes
void printMenu();
void addElement(int *array, int *size);
void removeElement(int *array, int *size);
void printArray(int *array, int size);
void reverseArray(int *array, int start, int end);
int searchElement(int *array, int size, int target);
void freeResources(int *array);

// Main function
int main() {
    int *array = (int *)malloc(MAX_SIZE * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    int size = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addElement(array, &size);
                break;
            case 2:
                removeElement(array, &size);
                break;
            case 3:
                printArray(array, size);
                break;
            case 4:
                reverseArray(array, 0, size - 1);
                printf("Array reversed successfully.\n");
                break;
            case 5:
                {
                    int target;
                    printf("Enter the element to search for: ");
                    if (scanf("%d", &target) != 1) {
                        fprintf(stderr, "Invalid input. Please enter a number.\n");
                        // Clear the input buffer
                        while (getchar() != '\n');
                        break;
                    }
                    int index = searchElement(array, size, target);
                    if (index != -1) {
                        printf("Element %d found at index %d.\n", target, index);
                    } else {
                        printf("Element %d not found in the array.\n", target);
                    }
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 6);

    freeResources(array);
    return EXIT_SUCCESS;
}

// Function to print the menu
void printMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add Element\n");
    printf("2. Remove Element\n");
    printf("3. Print Array\n");
    printf("4. Reverse Array\n");
    printf("5. Search Element\n");
    printf("6. Exit\n");
}

// Function to add an element to the array
void addElement(int *array, int *size) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot add more elements.\n");
        return;
    }

    int element;
    printf("Enter the element to add: ");
    if (scanf("%d", &element) != 1) {
        fprintf(stderr, "Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); // Clear the input buffer
        return;
    }

    array[*size] = element;
    (*size)++;
    printf("Element %d added successfully.\n", element);
}

// Function to remove an element from the array
void removeElement(int *array, int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot remove elements.\n");
        return;
    }

    int index;
    printf("Enter the index of the element to remove (0 to %d): ", *size - 1);
    if (scanf("%d", &index) != 1 || index < 0 || index >= *size) {
        fprintf(stderr, "Invalid input. Please enter a valid index.\n");
        while (getchar() != '\n'); // Clear the input buffer
        return;
    }

    for (int i = index; i < (*size) - 1; i++) {
        array[i] = array[i + 1];
    }

    (*size)--;
    printf("Element at index %d removed successfully.\n", index);
}

// Function to print the array
void printArray(int *array, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Recursive function to reverse the array
void reverseArray(int *array, int start, int end) {
    if (start >= end) {
        return;
    }
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    reverseArray(array, start + 1, end - 1);
}

// Function to search for an element in the array
int searchElement(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;  // Return index of the found element
        }
    }
    return -1; // Element not found
}

// Function to free allocated memory
void freeResources(int *array) {
    free(array);
}