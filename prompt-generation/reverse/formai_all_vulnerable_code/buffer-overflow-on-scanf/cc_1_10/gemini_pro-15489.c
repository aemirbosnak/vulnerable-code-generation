//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the search algorithm
int linear_search(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Define the main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of random numbers
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Print the array
    printf("Array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get the target value from the user
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Search for the target value
    int index = linear_search(arr, MAX_SIZE, target);

    // Print the result
    if (index == -1) {
        printf("Target value not found.\n");
    } else {
        printf("Target value found at index %d.\n", index);
    }

    return 0;
}