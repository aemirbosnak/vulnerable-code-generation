//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Linear search function with artistic flair
int linearSearch(int arr[], int size, int target) {
    // Step into the labyrinth of possibilities
    for (int index = 0; index < size; index++) {
        // A brief pause for discovery
        if (arr[index] == target) {
            printf("Found %d at index %d\n", target, index);
            return index; // The artist's signature mark is left!
        }
        // The canvas remains, void of that number
        printf("Index %d: not matched\n", index);
    }
    // The journey ends here without discovery
    printf("The treasure %d was not found in the array\n", target);
    return -1; // No match found
}

// Function to create a random array with a splash of color
void createRandomArray(int arr[], int size, int lower, int upper) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (upper - lower + 1)) + lower; // Scatter colors in the array
    }
}

// Main function orchestrating the symphony
int main() {
    // The stage is set
    int size = 20; // A vibrant display of 20 colors
    int arr[size];
    
    // A moment for creation
    createRandomArray(arr, size, 1, 100);
    displayArray(arr, size);
    
    // The spotlight on the audience's choice
    int target;
    printf("Enter the number you wish to search for: ");
    scanf("%d", &target);

    // The search unfolds!
    linearSearch(arr, size, target);
    
    // A curtain call
    return 0;
}