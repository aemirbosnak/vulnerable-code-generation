//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

// Function to perform binary search recursively
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2; // Calculate mid point
        
        // Check if target is at mid
        if (arr[mid] == target) {
            return mid; // Return the index if found
        }
        
        // If target is smaller than mid, search in the left subarray
        if (arr[mid] > target) {
            return recursiveBinarySearch(arr, left, mid - 1, target);
        }
        
        // If target is larger than mid, search in the right subarray
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }
    // Target is not present in array
    return -1;
}

// Function to display the menu
void displayMenu() {
    printf("-------- Binary Search Menu --------\n");
    printf("1. Search for a Number\n");
    printf("2. Exit\n");
    printf("------------------------------------\n");
}

// Function to get user input for the array
void inputArray(int arr[], int size) {
    printf("Enter %d sorted numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int size, target, result;

    // Prompt user for array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Validate the size
    if (size <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int arr[size];

    // Input the sorted array
    inputArray(arr, size);

    while (1) {
        displayMenu();
        int choice;
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter the number to search for: ");
            scanf("%d", &target);
            
            result = recursiveBinarySearch(arr, 0, size - 1, target);
            
            if (result != -1) {
                printf("Number found at index: %d\n", result);
            } else {
                printf("Number not found in the array.\n");
            }
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}