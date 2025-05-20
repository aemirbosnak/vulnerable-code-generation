//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

#define MAX_SIZE 100  // Maximum number of elements in the array

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    // Loop through the array to find the target
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE]; // Array to hold the numbers
    int n; // Number of elements in the array
    int target; // Number to search for
    int result; // Variable to store the result of the search

    // Prompt user to enter the number of elements
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Check for valid input
    if (n <= 0 || n > MAX_SIZE) {
        printf("Error: Invalid number of elements!\n");
        return 1; // Exit with error code
    }

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]); // Read each element
    }

    // Display the input array
    displayArray(arr, n);

    // Prompt user to enter the target number to search
    printf("Enter the number to search for: ");
    scanf("%d", &target);

    // Perform linear search
    result = linearSearch(arr, n, target);
    
    // Display the result
    if (result != -1) {
        printf("Number %d found at index %d.\n", target, result);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    return 0; // Successful termination of the program
}