//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the structure of each element in the array
struct element {
    int value;
    int index;
};

// Define the search function
void search(struct element arr[], int size, int target) {
    int i;

    // Loop through the array
    for (i = 0; i < size; i++) {
        // Check if the current element matches the target
        if (arr[i].value == target) {
            // Print the index of the element
            printf("Element found at index %d\n", arr[i].index);
            return;
        }
    }

    // Print a message if the element is not found
    printf("Element not found\n");
}

// Define the main function
int main() {
    int i, target, size;

    // Initialize the array
    struct element arr[MAX_SIZE];

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    // Get the target value from the user
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Call the search function
    search(arr, size, target);

    // Exit the program
    return 0;
}