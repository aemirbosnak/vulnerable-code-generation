//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>

#define MAX_SIZE 100

// Function to fill the array with user-defined values
void fillArray(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("The array contents are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size, target, result;

    printf("Welcome to the Linear Search Program!\n");
    
    // Ensuring the size doesn't exceed MAX_SIZE
    do {
        printf("Enter the number of elements you want to store (up to %d): ", MAX_SIZE);
        scanf("%d", &size);
    } while (size <= 0 || size > MAX_SIZE);

    // Fill the array with user inputs
    fillArray(arr, size);
    
    // Displaying the array
    displayArray(arr, size);
    
    // Taking target input
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    // Performing linear search
    result = linearSearch(arr, size, target);
    
    // Displaying results
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0; // End the program successfully
}