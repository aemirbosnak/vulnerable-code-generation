//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void menu();
void linear_search(int arr[], int size, int target);
void binary_search(int arr[], int size, int target);
void populate_array(int arr[], int size);
void display_array(int arr[], int size);

int main() {
    int choice, size, target;
    
    printf("Welcome to the Searching Algorithm Program!\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    populate_array(arr, size);
    
    while (1) {
        menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the target number for linear search: ");
                scanf("%d", &target);
                linear_search(arr, size, target);
                break;
            case 2:
                printf("Enter the target number for binary search: ");
                scanf("%d", &target);
                binary_search(arr, size, target);
                break;
            case 3:
                printf("Exiting program.\n");
                free(arr);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Exit\n");
}

void linear_search(int arr[], int size, int target) {
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = 1;
            printf("Element %d found at index %d (Linear Search).\n", target, i);
            break;
        }
    }
    
    if (!found) {
        printf("Element %d not found (Linear Search).\n", target);
    }
}

void binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;
    int found = 0;

    // Ensure the array is sorted for binary search
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            found = 1;
            printf("Element %d found at index %d (Binary Search).\n", target, mid);
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

void populate_array(int arr[], int size) {
    printf("Populating the array with random values...\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
    display_array(arr, size);
}

void display_array(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}