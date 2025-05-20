//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void fillArrayWithRandomNumbers(int *array, int size);
void printArray(int *array, int size);
int linearSearch(int *array, int size, int target);

int main() {
    srand(time(NULL));  // Seed the random number generator
    int *array;
    int size;
    int target;
    int result;

    // Welcome message!
    printf("🎉 Welcome to the Thrilling Linear Search Adventure! 🎉\n");
    printf("Let's create an array of magical numbers!\n");

    // Input size for dynamic array allocation
    printf("Enter the size of the array (up to 100): ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("🔥 Oops! Size must be between 1 and 100. Please try again! 🔥\n");
        return 1;
    }

    // Dynamic memory allocation for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("⚠️ Memory allocation failed! ⚠️\n");
        return 1;
    }

    // Fill the array with random numbers
    fillArrayWithRandomNumbers(array, size);

    // Display the filled array
    printf("✨ Here are your magical numbers: ✨\n");
    printArray(array, size);

    // Asking user for the target number to search
    printf("🔍 What magical number do you want to find? ");
    scanf("%d", &target);

    // Performing linear search
    printf("🎯 Searching for %d in the magical array...\n", target);
    result = linearSearch(array, size, target);

    // Display the result
    if (result == -1) {
        printf("😢 Oh no! %d is not in the array! Better luck next time!\n", target);
    } else {
        printf("🎉 Hooray! We found %d at position %d! 🎉\n", target, result);
    }

    // Free the allocated memory
    free(array);
    printf("🚀 Thanks for exploring the magical world of searching with us! Goodbye! 🚀\n");
    return 0;
}

// Function to fill an array with random numbers
void fillArrayWithRandomNumbers(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;  // Random numbers between 0 and 99
    }
}

// Function to print the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to perform linear search
int linearSearch(int *array, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;  // Return the index where the target is found
        }
    }
    return -1;  // Target not found
}