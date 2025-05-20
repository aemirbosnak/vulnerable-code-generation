//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void displayMenu();
void linearSearch(int arr[], int size, int target);
void binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);
int compare(const void *a, const void *b);
void getUserInput(int *arr, int *size);

// Main Function
int main() {
    int arr[100], size = 0, target = 0, choice = 0;

    getUserInput(arr, &size);

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Linear Search
                printf("Enter the element to be searched: ");
                scanf("%d", &target);
                linearSearch(arr, size, target);
                break;
            case 2: // Binary Search
                printf("Enter the element to be searched: ");
                scanf("%d", &target);
                sortArray(arr, size);
                binarySearch(arr, size, target);
                break;
            case 3: // Exit
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Display Menu Function
void displayMenu() {
    printf("\n*** Search Algorithm Menu ***\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array needs to be sorted)\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

// Linear Search Function
void linearSearch(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d (Linear Search).\n", target, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found (Linear Search).\n", target);
    }
}

// Binary Search Function
void binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int mid, found = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            printf("Element %d found at index %d (Binary Search).\n", target, mid);
            found = 1;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found (Binary Search).\n", target);
    }
}

// Function to Sort Array (for Binary Search)
void sortArray(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

// Compare Function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// User Input Function
void getUserInput(int *arr, int *size) {
    printf("Enter the number of elements (max 100): ");
    scanf("%d", size);

    printf("Enter %d integers:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}