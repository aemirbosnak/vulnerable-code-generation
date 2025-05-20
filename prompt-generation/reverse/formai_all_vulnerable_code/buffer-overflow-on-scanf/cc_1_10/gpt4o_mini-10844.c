//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define NOT_FOUND -1

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return NOT_FOUND; // Return NOT_FOUND if the element is not present
}

void fillArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Fill with random numbers from 0 to 99
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Set the size of the array
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate size
    if(size <= 0 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Fill the array with random numbers
    fillArray(arr, size);
    printArray(arr, size);

    // The oh-so-important number we seek
    int target;
    printf("Enter the number you wish to find: ");
    scanf("%d", &target);

    // Searching for the target number
    printf("Initiating the search for %d...\n", target);
    int result = linearSearch(arr, size, target);

    // Providing feedback based on the search result
    if(result != NOT_FOUND) {
        printf("Hooray! The number %d was found at index %d.\n", target, result);
    } else {
        printf("Alas! The number %d was not found in the array.\n", target);
    }

    // The great exit
    printf("Thank you for playing our grand search adventure!\n");
    return 0;
}