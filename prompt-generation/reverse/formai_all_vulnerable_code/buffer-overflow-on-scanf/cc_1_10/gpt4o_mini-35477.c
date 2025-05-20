//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100

// Function to compare two integers for sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function to perform binary search
int binarySearch(int* array, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid; // Target found
        }
        if (array[mid] < target) {
            left = mid + 1; // Move to the right half
        } else {
            right = mid - 1; // Move to the left half
        }
    }
    return -1; // Target not found
}

// Function to ensure that the input is unique
int isUnique(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

int main() {
    int* numbers = malloc(MAX_INPUT * sizeof(int));
    int count = 0;
    int input;
    char choice;

    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Welcome to the Protected Binary Search Program!\n");
    do {
        printf("Enter an integer (or type 'q' to stop): ");
        if (scanf("%d", &input) == 1) {
            if (count < MAX_INPUT) {
                if (isUnique(numbers, count, input)) {
                    numbers[count++] = input; // Store unique input
                } else {
                    printf("Duplicate entry, please enter a unique integer.\n");
                }
            } else {
                printf("Maximum input limit reached.\n");
            }
        } else {
            scanf("%c", &choice); // Clear buffer
            if (choice == 'q' || choice == 'Q') break; // User wants to quit
            printf("Invalid input! Please enter an integer.\n");
            while(getchar() != '\n'); // Clear invalid input
        }
    } while (1);

    // Sort the unique numbers
    qsort(numbers, count, sizeof(int), compare);

    // Prompt for binary search
    printf("Current unique integers:\n");
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    printf("Enter an integer to search: ");
    scanf("%d", &input);

    // Perform binary search
    int result = binarySearch(numbers, count, input);

    if (result != -1) {
        printf("Integer %d found at index: %d\n", input, result);
    } else {
        printf("Integer %d not found in the array.\n", input);
    }

    free(numbers);
    return 0;
}