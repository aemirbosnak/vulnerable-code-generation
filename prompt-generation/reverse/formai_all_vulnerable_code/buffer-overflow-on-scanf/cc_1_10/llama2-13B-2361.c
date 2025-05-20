//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer array
void generateRandomArray(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}

// Function to print the array elements
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to check if the user guessed the correct element
int checkGuess(int *arr, int size, int guess) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == guess) {
            return 1; // Return 1 if the guess is correct
        }
    }
    return 0; // Return 0 if the guess is not correct
}

int main() {
    int arr[10]; // Generate a random integer array of size 10
    generateRandomArray(arr, 10);

    int guess = 0; // Initialize the guess variable

    while (1) {
        // Print the array elements
        printArray(arr, 10);

        // Ask the user to guess an element
        printf("Guess an element: ");
        scanf("%d", &guess);

        // Check if the user guessed the correct element
        if (checkGuess(arr, 10, guess)) {
            break; // If the guess is correct, break out of the loop
        }

        // If the guess is not correct, print an error message
        printf("Oops! That's not the correct element. Try again:\n");
    }

    return 0; // Program ends here
}