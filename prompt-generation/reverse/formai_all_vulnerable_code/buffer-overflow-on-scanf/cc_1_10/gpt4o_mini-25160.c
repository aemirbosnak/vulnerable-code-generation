//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

void print_menu() {
    printf("\nWelcome to the Ken Thompson Style Search Program!\n");
    printf("1. Input Array\n");
    printf("2. Search for an Element\n");
    printf("3. Exit\n");
}

void input_array(int **array, int *size) {
    printf("Enter the number of elements (max 100): ");
    scanf("%d", size);
    
    if (*size > MAX_ELEMENTS || *size <= 0) {
        printf("Invalid size! Must be between 1 and %d.\n", MAX_ELEMENTS);
        *size = 0;
        return;
    }

    *array = (int *)malloc(*size * sizeof(int));
    if (*array == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*array)[i]);
    }
    printf("Array successfully populated!\n");
}

int linear_search(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Not found
}

void search_element(int *array, int size) {
    if (size == 0) {
        printf("No elements in the array. Please input an array first.\n");
        return;
    }
    
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = linear_search(array, size, target);
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
}

void free_resources(int *array) {
    if (array) {
        free(array);
    }
}

int main() {
    int *array = NULL;
    int size = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_array(&array, &size);
                break;
            case 2:
                search_element(array, size);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                free_resources(array);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}