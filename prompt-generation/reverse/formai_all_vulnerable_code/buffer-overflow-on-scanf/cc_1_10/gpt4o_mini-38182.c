//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void sortArray(int arr[], int size);
void displayMenu();
void handleUserInput(int choice);

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], size, choice;

    // Initialize array
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if(size > MAX_SIZE || size <= 0) {
        printf("Invalid array size. Exiting.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Main program loop
    while(1) {
        displayMenu();
        scanf("%d", &choice);
        
        // Exit case
        if(choice == 4) {
            printf("Exiting the program.\n");
            break;
        }

        handleUserInput(choice);
    }

    return EXIT_SUCCESS;
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // Return index where target is found
        }
    }
    return -1; // If target not found
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            return mid; // Return index where target is found
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // If target not found
}

void sortArray(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayMenu() {
    printf("---------- Menu ----------\n");
    printf("1. Display array\n");
    printf("2. Perform Linear Search\n");
    printf("3. Perform Binary Search\n");
    printf("4. Exit\n");
    printf("--------------------------\n");
    printf("Enter your choice: ");
}

void handleUserInput(int choice) {
    int target, size;
    int arr[MAX_SIZE];
    
    switch(choice) {
        case 1: 
            // Display the array
            printf("Displaying the array.\n");
            break;

        case 2: 
            // Linear Search
            printf("Enter the target element for Linear Search: ");
            scanf("%d", &target);
            int index = linearSearch(arr, size, target);
            if(index != -1) {
                printf("Element %d found at index %d using Linear Search.\n", target, index);
            } else {
                printf("Element %d not found using Linear Search.\n", target);
            }
            break;

        case 3: 
            // Binary Search requires sorted array
            sortArray(arr, size);
            displayArray(arr, size);
            printf("Enter the target element for Binary Search: ");
            scanf("%d", &target);
            index = binarySearch(arr, size, target);
            if(index != -1) {
                printf("Element %d found at index %d using Binary Search.\n", target, index);
            } else {
                printf("Element %d not found using Binary Search.\n", target);
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
}