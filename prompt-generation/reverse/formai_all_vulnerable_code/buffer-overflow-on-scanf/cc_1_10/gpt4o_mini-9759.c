//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void displayMenu() {
    printf("\n=== Array Search Program ===\n");
    printf("1. Input an array\n");
    printf("2. Search for an element\n");
    printf("3. Display the array\n");
    printf("4. Clear the array\n");
    printf("5. Exit\n");
    printf("============================\n");
    printf("Choose an option: ");
}

void inputArray(int *arr, int *size) {
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", size);
    if (*size > MAX_SIZE) {
        printf("Size exceeds maximum limit. Please enter a value up to %d.\n", MAX_SIZE);
        *size = 0;
        return;
    }
    
    printf("Enter the elements:\n");
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int linearSearch(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return index of found element
        }
    }
    return -1; // Element not found
}

void displayArray(int *arr, int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void clearArray(int *arr, int *size) {
    *size = 0; // Simply set size to zero indicates clear
    printf("Array cleared.\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0, option, key, result;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                if (size == 0) {
                    printf("Please input an array first.\n");
                } else {
                    printf("Enter the element to search for: ");
                    scanf("%d", &key);
                    result = linearSearch(arr, size, key);
                    if (result != -1) {
                        printf("Element %d found at index %d.\n", key, result);
                    } else {
                        printf("Element %d not found in the array.\n", key);
                    }
                }
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                clearArray(arr, &size);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}