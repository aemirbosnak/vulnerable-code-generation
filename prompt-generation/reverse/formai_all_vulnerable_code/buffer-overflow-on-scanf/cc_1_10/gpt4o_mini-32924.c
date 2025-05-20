//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void print_array(int arr[], int size);
int linear_search(int arr[], int size, int target);
int binary_search(int arr[], int size, int target);

int main() {
    int size, choice, target;

    // Peaceful greeting message
    printf("Welcome to the Searching Algorithm Program!\n");
    printf("Let's explore the beauty of linear and binary searching.\n");

    // Input size of the array
    printf("Please enter the size of the array: ");
    scanf("%d", &size);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate array with peaceful integers
    printf("Kindly enter %d integers for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the array for serenity
    printf("Here is your serene array: ");
    print_array(arr, size);

    // Asking user for the search choice
    printf("\nChoose a search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Array must be sorted first)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Target integer input
    printf("Please enter the integer you wish to search for: ");
    scanf("%d", &target);

    // Search operations based on user choice
    switch (choice) {
        case 1: {
            int result = linear_search(arr, size, target);
            if (result != -1) {
                printf("Linear Search found the target %d at index %d.\n", target, result);
            } else {
                printf("Linear Search did not find the target %d in the array.\n", target);
            }
            break;
        }
        case 2: {
            // Sort the array before binary search
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        // Swap arr[j] and arr[j + 1]
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            printf("Array has been sorted for binary search: ");
            print_array(arr, size);
            int result = binary_search(arr, size, target);
            if (result != -1) {
                printf("Binary Search found the target %d at index %d.\n", target, result);
            } else {
                printf("Binary Search did not find the target %d in the sorted array.\n", target);
            }
            break;
        }
        default:
            printf("Invalid choice, please run the program again.\n");
    }

    // Free the dynamically allocated memory
    free(arr);
    printf("Thank you for exploring with us! Have a peaceful day!\n");
    return 0;
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function for linear search
int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the target
        }
    }
    return -1; // Target not found
}

// Function for binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}