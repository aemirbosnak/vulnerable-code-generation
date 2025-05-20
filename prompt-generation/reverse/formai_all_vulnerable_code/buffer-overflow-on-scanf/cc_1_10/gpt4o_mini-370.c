//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function prototype
int linearSearch(int arr[], int size, int target);

int main() {
    int size, target, result;
    char choice;

    printf("Welcome to the Dynamic Linear Search Program!\n\n");

    // Dynamic size allocation for the array
    printf("Let's create an array, how many elements do you want to input? ");
    scanf("%d", &size);

    // Validating correct sizes
    while (size <= 0) {
        printf("Please enter a positive integer for the size of the array: ");
        scanf("%d", &size);
    }

    // Dynamically allocating memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    // Input elements into the array
    printf("Great! Now, please enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        // Taking user input for the target element to search
        printf("\nEnter the number you want to search for: ");
        scanf("%d", &target);

        // Calling linear search function
        result = linearSearch(arr, size, target);

        // Displaying the search result
        if (result != -1) {
            printf("Hooray! The number %d is found at index %d.\n", target, result);
        } else {
            printf("Oops! The number %d is not found in the array.\n", target);
        }

        // Asking the user if they want to continue searching
        printf("Do you want to search for another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Freeing the dynamically allocated memory
    free(arr);
    printf("\nThank you for using the Dynamic Linear Search Program! Goodbye!\n");
    
    return 0;
}

// Function to perform a linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}