//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define STRING_SIZE 50

// Function declarations
void initializeArray(char arr[][STRING_SIZE], int size);
void displayArray(char arr[][STRING_SIZE], int size);
int linearSearch(char arr[][STRING_SIZE], int size, const char *target);
int binarySearch(char arr[][STRING_SIZE], int size, const char *target);
void sortArray(char arr[][STRING_SIZE], int size);

int main() {
    char arr[MAX_SIZE][STRING_SIZE];
    int size, choice;
    char target[STRING_SIZE];

    printf("Enter the number of strings (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size. Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Initialize the array with strings
    initializeArray(arr, size);

    printf("Array of strings initialized:\n");
    displayArray(arr, size);

    printf("Choose search method:\n1. Linear Search\n2. Binary Search\nEnter choice (1/2): ");
    scanf("%d", &choice);

    printf("Enter the string to search for: ");
    scanf("%s", target);

    int index = -1;
    
    if (choice == 1) {
        index = linearSearch(arr, size, target);
    } else if (choice == 2) {
        sortArray(arr, size); // Sort before binary search
        index = binarySearch(arr, size, target);
    } else {
        printf("Invalid choice! Please select 1 or 2.\n");
        return 1;
    }

    if (index != -1) {
        printf("String '%s' found at index %d.\n", target, index);
    } else {
        printf("String '%s' not found in the array.\n", target);
    }

    return 0;
}

// Function to initialize the array with random strings
void initializeArray(char arr[][STRING_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        snprintf(arr[i], STRING_SIZE, "String%d", rand() % 100);
    }
}

// Function to display the array of strings
void displayArray(char arr[][STRING_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

// Linear Search implementation
int linearSearch(char arr[][STRING_SIZE], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) {
            return i;
        }
    }
    return -1; // Target not found
}

// Binary Search implementation
int binarySearch(char arr[][STRING_SIZE], int size, const char *target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(arr[mid], target);
        if (cmp == 0) {
            return mid; // Target found
        } else if (cmp < 0) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

// Function to sort the array using bubble sort
void sortArray(char arr[][STRING_SIZE], int size) {
    char temp[STRING_SIZE];
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}