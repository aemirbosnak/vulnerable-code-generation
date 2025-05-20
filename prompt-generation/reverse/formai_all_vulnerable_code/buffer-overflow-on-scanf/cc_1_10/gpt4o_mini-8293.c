//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define INPUT_SIZE 20

// Function prototypes
void fillArray(int *array, int size);
int binarySearch(int *array, int size, int target);
int secureInput(const char *prompt);
void clearInputBuffer();

// Main function
int main() {
    int size;
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    clearInputBuffer(); // Clear the newline from the input buffer

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a size between 1 and %d.\n", MAX_SIZE);
        return EXIT_FAILURE;
    }

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate memory for the array");
        return EXIT_FAILURE;
    }

    fillArray(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int target = secureInput("Enter the number to search for: ");
    int index = binarySearch(array, size, target);

    if (index != -1) {
        printf("Number %d found at index %d.\n", target, index);
    } else {
        printf("Number %d not found in the array.\n", target);
    }

    free(array);
    return EXIT_SUCCESS;
}

// Function to fill the array with random numbers and sort it
void fillArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    // Sort the array using simple bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to conduct a binary search
int binarySearch(int *array, int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid potential overflow

        if (array[mid] == target) {
            return mid; // Target found
        }

        if (array[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    
    return -1; // Target not found
}

// Function to securely get input from user, preventing buffer overflow
int secureInput(const char *prompt) {
    char input[INPUT_SIZE];
    
    printf("%s", prompt);
    if (!fgets(input, sizeof(input), stdin)) {
        perror("Failed to read input");
        exit(EXIT_FAILURE);
    }

    // Convert the input string to an integer
    int value = atoi(input);
    return value;
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}