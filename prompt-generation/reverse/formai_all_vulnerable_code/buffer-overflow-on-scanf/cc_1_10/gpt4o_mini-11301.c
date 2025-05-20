//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function prototypes
void generate_array(int arr[], int size);
void print_array(int arr[], int size);
int linear_search(int arr[], int size, int target);
int binary_search(int arr[], int size, int target);

int main() {
    int arr[MAX];
    int size, choice, target, index;

    // Asking for the size of the array
    printf("Enter the number of elements in the array (max %d): ", MAX);
    scanf("%d", &size);

    // Validating size
    if(size < 1 || size > MAX) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    // Generating random array
    generate_array(arr, size);
    printf("Generated Array:\n");
    print_array(arr, size);

    // Asking user for choice of search
    printf("Choose the search method:\n1. Linear Search\n2. Binary Search\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);

    // Asking for the target number to search
    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    // Call the respective search function based on user choice
    if (choice == 1) {
        index = linear_search(arr, size, target);
        if(index != -1)
            printf("Linear Search: Element found at index %d\n", index);
        else
            printf("Linear Search: Element not found in the array.\n");
    } else if (choice == 2) {
        // Binary Search requires sorted array
        // Sort the array using simple bubble sort for demonstration
        for(int i = 0; i < size - 1; i++) {
            for(int j = 0; j < size - i - 1; j++) {
                if(arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        printf("Sorted Array for Binary Search:\n");
        print_array(arr, size);
        index = binary_search(arr, size, target);
        if(index != -1)
            printf("Binary Search: Element found at index %d\n", index);
        else
            printf("Binary Search: Element not found in the array.\n");
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
        return 1;
    }

    return 0;
}

// Function to generate an array with random integers
void generate_array(int arr[], int size) {
    srand(time(NULL)); // Seed for random number generation
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random number between 0 and 99
    }
}

// Function to print the array
void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Linear Search Implementation
int linear_search(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // Return the index where target is found
        }
    }
    return -1; // Return -1 if not found
}

// Binary Search Implementation
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) {
            return mid; // Target found
        }
        else if(arr[mid] < target) {
            left = mid + 1; // Search in the right half
        }
        else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Not found
}