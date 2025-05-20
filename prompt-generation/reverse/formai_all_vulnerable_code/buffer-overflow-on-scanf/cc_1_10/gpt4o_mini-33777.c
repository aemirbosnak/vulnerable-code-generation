//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Surprise Searching Algorithm! 🌟
// We are going to implement a binary search algorithm,
// but in a fun and unexpected way!

// Function to fill the array with random numbers
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Filling with random numbers from 0 to 99
    }
}

// Function to sort the array
void sortArray(int *arr, int size) {
    // Bubble sort, but who needs efficiency when we have surprise?
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Surprise! 🌀 Let's swap!
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform binary search
int binarySearch(int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Surprise check: if we find an unexpected number!
        if (arr[mid] == target) {
            printf("🎉 Surprise! Found %d at index %d!\n", target, mid);
            return mid;
        } else if (arr[mid] < target) {
            // Surprise! Time to go right!
            left = mid + 1;
        } else {
            // Surprise! Time to go left!
            right = mid - 1;
        }
    }

    // Surprise conclusion: we didn't find the number!
    printf("😢 Oops! %d is not in the array!\n", target);
    return -1;
}

// Function to print the array
void printArray(int *arr, int size) {
    printf("Array contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    int size, target;

    printf("Enter the size of the array (positive integer): ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("😱 Size must be greater than 0!\n");
        return -1;
    }

    int *arr = (int *)malloc(size * sizeof(int)); // Dynamic memory allocation
    if (arr == NULL) {
        printf("🚨 Memory allocation failed!\n");
        return -1;
    }

    fillArray(arr, size); // Fill the array with random numbers
    sortArray(arr, size); // Sort the array

    printf("Here's a surprise array for you!\n");
    printArray(arr, size); // Print the array

    printf("Enter the number you want to search for: ");
    scanf("%d", &target);

    // Call the binary search function
    binarySearch(arr, size, target);

    // Free the allocated memory
    free(arr);
    
    printf("🔚 Program has completed execution! Thank you for joining this surprise searching experience! 🎊\n");
    
    return 0;
}