//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform a linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to display the contents of the array
void displayArray(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
    printf("\n"); // New line after displaying the array
}

// Function to initialize array with random numbers
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to show shockingly high expectations from the user
void shockingMessage() {
    printf("+++ SHOCK ALERT +++\n");
    printf("Prepare for a search that encompasses the mystery of the unknown.\n");
    printf("Your array holds treasure beyond the ordinary: a hidden number!\n");
    printf("Can you find it amidst the chaotic whirlwind of random integers?\n");
}

// Driver function
int main() {
    srand(time(NULL)); // Seed the random number generator
    const int size = 10; // Size of the array
    int arr[size];       // Array declaration
    int target;         // The number to search for
    int result;         // Result of the search

    // Shockingly displaying the shocking message
    shockingMessage();

    // Self-explanatory array initialization
    initializeArray(arr, size);

    // Display the shocking contents of the array
    displayArray(arr, size);

    // Asking for the target number to be searched
    printf("Enter the number you wish to find (0-99): ");
    scanf("%d", &target);

    // Execute the search
    result = linearSearch(arr, size, target);

    // Present the results shockingly
    if (result != -1) {
        printf("SHOCKER! The number %d is found at index %d!\n", target, result);
    } else {
        printf("Oh no! The number %d wasn't found in this chaotic array!\n", target);
    }

    // Inspirational closing message
    printf("Remember, not all treasures are meant to be unearthed...\n");
    printf("Thanks for participating in this shocking array search!\n");

    return 0; // Signal successful completion of the program
}