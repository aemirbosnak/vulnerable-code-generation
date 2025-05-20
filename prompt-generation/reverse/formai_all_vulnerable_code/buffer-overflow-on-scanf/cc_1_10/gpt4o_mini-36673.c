//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
void performLinearSearch(int arr[], int size, int target);
void performBinarySearch(int arr[], int size, int target);
void bubbleSort(int arr[], int size);
int getInput();
void fillArray(int arr[], int size);

int main() {
    int size, choice, target;

    printf("Welcome to the Searching Algorithm Demonstrator!\n");
    printf("Please enter the size of the array: ");
    size = getInput();

    int *arr = (int *)malloc(size * sizeof(int));
    fillArray(arr, size);

    do {
        displayMenu();
        choice = getInput();

        switch(choice) {
            case 1: // Linear Search
                printf("Enter the value to search for (Linear Search): ");
                target = getInput();
                performLinearSearch(arr, size, target);
                break;

            case 2: // Binary Search
                bubbleSort(arr, size);
                printf("Array after sorting for Binary Search:\n");
                for(int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\nEnter the value to search for (Binary Search): ");
                target = getInput();
                performBinarySearch(arr, size, target);
                break;

            case 3: // Exit
                printf("Exiting program...\n");
                free(arr);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    free(arr);
    return 0;
}

void displayMenu() {
    printf("\nChoose a search algorithm:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (requires sorted array)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void performLinearSearch(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d (Linear Search)\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found (Linear Search)\n", target);
    }
}

void performBinarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int found = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Element %d found at index %d (Binary Search)\n", target, mid);
            found = 1;
            break;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Element %d not found (Binary Search)\n", target);
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int getInput() {
    int input;
    while (1) {
        printf("Input: ");
        if (scanf("%d", &input) != 1) {
            while(getchar() != '\n'); // Clear input buffer
            printf("Invalid input; please enter a number.\n");
            continue;
        }
        while(getchar() != '\n'); // Clear input buffer
        return input;
    }
}

void fillArray(int arr[], int size) {
    printf("Please enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        arr[i] = getInput();
    }
}