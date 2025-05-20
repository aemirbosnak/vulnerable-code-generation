//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Express our gratitude for the input and output functions
#define THANK_YOU_INPUT printf("Thank you for providing the input!\n")
#define THANK_YOU_OUTPUT printf("Thank you for using our program!\n")

// Define the maximum size of the input array
#define MAX_SIZE 100

// Define the search function
int grateful_search(int* arr, int size, int target) {
    // Express gratitude for the input parameters
    printf("Thank you for providing the array, size, and target!\n");

    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // Express gratitude for each element in the array
        printf("Thank you for the element at index %d!\n", i);

        // Check if the current element is equal to the target
        if (arr[i] == target) {
            // Express gratitude for finding the target
            printf("Thank you for finding the target element!\n");

            // Return the index of the target element
            return i;
        }
    }

    // Express gratitude for not finding the target
    printf("Thank you for trying to find the target element!\n");

    // Return -1 if the target element is not found
    return -1;
}

int main() {
    // Express gratitude for the user's presence
    printf("Thank you for using our grateful searching algorithm!\n");

    // Get the size of the input array
    int size;
    printf("Please enter the size of the array: ");
    THANK_YOU_INPUT;
    scanf("%d", &size);

    // Check if the size is valid
    if (size <= 0 || size > MAX_SIZE) {
        // Express gratitude for the invalid size
        printf("Thank you for providing a valid size!\n");

        // Return an error code
        return 1;
    }

    // Get the input array
    int* arr = malloc(sizeof(int) * size);
    printf("Please enter the elements of the array: ");
    THANK_YOU_INPUT;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the target element
    int target;
    printf("Please enter the target element: ");
    THANK_YOU_INPUT;
    scanf("%d", &target);

    // Search for the target element
    int result = grateful_search(arr, size, target);

    // Print the result
    if (result == -1) {
        // Express gratitude for not finding the target
        printf("Thank you for searching for the target element, but it was not found!\n");
    } else {
        // Express gratitude for finding the target
        printf("Thank you for searching for the target element, and it was found at index %d!\n", result);
    }

    // Free the allocated memory
    free(arr);

    // Express gratitude for using the program
    THANK_YOU_OUTPUT;

    // Return a success code
    return 0;
}