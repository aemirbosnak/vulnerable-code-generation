//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_array(int arr[], int size);
int binary_search(int arr[], int size, int target);
void handle_search_result(int result);

int main() {
    int size, target;
    
    printf("Welcome to the SHOCKING Binary Search Experience!\n");
    printf("Prepare for a journey through an array of numbers!\n\n");

    // Prompt user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    
    // Dynamic allocation of array
    int *arr = malloc(size * sizeof(int));
    printf("Behold, the array you will soon construct!\n");

    // Populate the array
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Sort the array for binary search
    printf("\nSorting the array... This might take a moment...\n");
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                // Swapping elements
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Array sorted! Here it is:\n");
    print_array(arr, size);

    // Prompt user for the target to search
    printf("\nEnter the number you wish to search for: ");
    scanf("%d", &target);

    // Conduct the search
    printf("Searching... hold on tight!\n");
    int result = binary_search(arr, size, target);

    // Handle the result
    handle_search_result(result);
    
    // Free the dynamically allocated memory
    free(arr);

    return 0;
}

// Function to print the array
void print_array(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Binary search function
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        printf("Checking middle element: %d\n", arr[mid]);

        if (arr[mid] == target) {
            printf("Found a match! You were looking for %d!\n", target);
            return mid; // Found the target, return its index
        }
        else if (arr[mid] < target) {
            printf("The middle element is less than your target! Searching right...\n");
            left = mid + 1; // Target is in the right half
        }
        else {
            printf("The middle element is greater than your target! Searching left...\n");
            right = mid - 1; // Target is in the left half
        }
    }
    return -1; // Target not found
}

// Function to handle search result
void handle_search_result(int result) {
    if (result == -1) {
        printf("*** SHOCKING NEWS ***\n");
        printf("The number you were looking for is NOT in the array!\n");
    } else {
        printf("The number is located at index: %d\n", result);
    }
}