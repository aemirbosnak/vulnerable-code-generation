//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void generateRandomArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
void displayArray(int arr[], int size);
void printWelcomeMessage();
void printGoodbyeMessage();

int main() {
    // Display a friendly welcome message
    printWelcomeMessage();

    int size, target, index;
    int arr[MAX_SIZE];

    // Asking the user for the size of the array
    printf("Please enter the size of the array (1-%d): ", MAX_SIZE);
    scanf("%d", &size);
    
    // Ensuring the size is within acceptable limits
    if (size < 1 || size > MAX_SIZE) {
        printf("Oops! The size must be between 1 and %d. Please try again.\n", MAX_SIZE);
        return 1;
    }

    // Generating a random array
    generateRandomArray(arr, size);
    
    // Displaying the array to the user
    printf("Here's your random array:\n");
    displayArray(arr, size);

    // Asking the user for the target number to search
    printf("What number would you like to search for in the array? ");
    scanf("%d", &target);

    // Searching for the target number in the array
    index = linearSearch(arr, size, target);
    
    // Displaying the results of the search
    if (index != -1) {
        printf("Fantastic! The number %d was found at index %d!\n", target, index);
    } else {
        printf("Sad news! The number %d was not found in the array...\n", target);
    }

    // Print a cheerful goodbye message
    printGoodbyeMessage();

    return 0;
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Random numbers from 0 to 99
    }
}

// Function to perform linear search on the array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index where the target is found
        }
    }
    return -1; // Return -1 if target is not found
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print a welcome message
void printWelcomeMessage() {
    printf("🌟 Welcome to the Happy Search Program! 🌟\n");
    printf("📦 Let's create a random array and search for your favorite number! 📦\n");
}

// Function to print a goodbye message
void printGoodbyeMessage() {
    printf("🎉 Thank you for using the Happy Search Program! 🎉\n");
    printf("🌈 Have a wonderful day! 🌈\n");
}