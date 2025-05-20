//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to compare two strings
int compare_strings(const char* a, const char* b) {
    return strcmp(a, b);
}

// Function to search for a string in an array of strings using linear search
int linear_search(const char** arr, int size, const char* target) {
    for (int i = 0; i < size; i++) {
        if (compare_strings(arr[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to search for a string in an array of strings using binary search
int binary_search(const char** arr, int size, const char* target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int comparison = compare_strings(arr[mid], target);

        if (comparison == 0) {
            return mid;
        } else if (comparison < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

// Function to print an array of strings
void print_array(const char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of strings
    const char* arr[] = {"Hello", "World", "C", "Programming", "Language"};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the array
    printf("Array: ");
    print_array(arr, size);

    // Get the target string from the user
    char target[MAX_SIZE];
    printf("Enter the target string: ");
    scanf("%s", target);

    // Search for the target string using linear search
    int linear_search_result = linear_search(arr, size, target);

    // Search for the target string using binary search
    int binary_search_result = binary_search(arr, size, target);

    // Print the results
    if (linear_search_result == -1) {
        printf("Linear search: Target string not found.\n");
    } else {
        printf("Linear search: Target string found at index %d.\n", linear_search_result);
    }

    if (binary_search_result == -1) {
        printf("Binary search: Target string not found.\n");
    } else {
        printf("Binary search: Target string found at index %d.\n", binary_search_result);
    }

    return 0;
}