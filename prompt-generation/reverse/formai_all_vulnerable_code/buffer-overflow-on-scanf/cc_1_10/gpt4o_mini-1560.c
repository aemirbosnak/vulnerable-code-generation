//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void displayMenu() {
    printf("\n--- Simple Search Program ---\n");
    printf("1. Add Element\n");
    printf("2. Search Element\n");
    printf("3. Display Elements\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int addElement(int arr[], int *count) {
    if (*count >= MAX_SIZE) {
        printf("Array is full!\n");
        return 0;
    }
    int element;
    printf("Enter the element to add: ");
    scanf("%d", &element);
    arr[(*count)++] = element;
    printf("Element %d added successfully!\n", element);
    return 1;
}

int linearSearch(int arr[], int count, int target) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == target) {
            return i; // Return the index of found element
        }
    }
    return -1; // Not found
}

void displayElements(int arr[], int count) {
    if (count == 0) {
        printf("No elements to display.\n");
        return;
    }
    printf("Current elements in the array:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addElement(arr, &count);
                break;
            case 2: {
                int target;
                printf("Enter the element to search: ");
                scanf("%d", &target);
                int result = linearSearch(arr, count, target);
                if (result != -1) {
                    printf("Element %d found at index %d.\n", target, result);
                } else {
                    printf("Element %d not found in the array.\n", target);
                }
                break;
            }
            case 3:
                displayElements(arr, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select from the menu.\n");
        }
    }
    
    return 0;
}