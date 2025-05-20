//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>

#define MAX_SIZE 100

void displayMenu() {
    printf("\n========================= \n");
    printf("    Integer Search App    \n");
    printf("========================= \n");
    printf("1. Enter numbers\n");
    printf("2. Search for a number\n");
    printf("3. Exit\n");
    printf("========================= \n");
    printf("Please select an option (1-3): ");
}

void enterNumbers(int arr[], int *size) {
    printf("Enter the number of integers (max %d): ", MAX_SIZE);
    scanf("%d", size);

    if (*size > MAX_SIZE) {
        printf("Error: Maximum size exceeded! Using max size %d.\n", MAX_SIZE);
        *size = MAX_SIZE;
    }

    printf("Please enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Index where the target is found
        }
    }
    return -1; // Not found
}

void searchNumber(int arr[], int size) {
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);
    if (result != -1) {
        printf("The number %d was found at index %d.\n", target, result);
    } else {
        printf("The number %d was NOT found in the list.\n", target);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterNumbers(arr, &size);
                break;
            case 2:
                if (size == 0) {
                    printf("Please enter numbers first!\n");
                } else {
                    searchNumber(arr, size);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}