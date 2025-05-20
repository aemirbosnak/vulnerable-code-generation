//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array contents: [ ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        printf("Checking index %d: value %d\n", i, arr[i]); // Show progress
        if(arr[i] == target) {
            printf("Found %d at index %d\n", target, i);
            return i; // Return index of the found element
        }
    }
    printf("Value %d not found in the array.\n", target);
    return -1; // Indicate not found
}

void fillArrayWithRandomNumbers(int arr[], int size) {
    srand(time(0)); // Seed for random number generation
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Filling array with random values from 0 to 99
    }
}

int main() {
    int arr[MAX_SIZE];
    int size, target, result;

    printf("Welcome to the Linear Search Visualizer!\n");
    printf("How many numbers do you want in your array (1 to %d)? ", MAX_SIZE);
    
    // Get the size of the array from the user
    scanf("%d", &size);
    if(size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please run the program again.\n");
        return -1;
    }

    fillArrayWithRandomNumbers(arr, size); // Fill the array with random numbers
    displayArray(arr, size); // Display the initial array

    printf("Enter the number you want to search for: ");
    scanf("%d", &target); // Get target number to search
    
    printf("\nStarting linear search for %d...\n", target);
    result = linearSearch(arr, size, target); // Perform linear search

    if(result != -1) {
        printf("Number %d found at index %d!\n", target, result);
    } else {
        printf("Number %d was not found in the array.\n", target);
    }

    return 0;
}