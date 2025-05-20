//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function to securely clear the buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Recursive function to perform a binary search in a sorted array
int binary_search(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid; // Element found
    }

    if (arr[mid] > target) {
        return binary_search(arr, left, mid - 1, target); // Search left
    } else {
        return binary_search(arr, mid + 1, right, target); // Search right
    }
}

// Function to input a sorted array
void input_sorted_array(int arr[], int size) {
    printf("Enter %d sorted integers:\n", size);
    for (int i = 0; i < size; i++) {
        while (1) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. Please enter an integer: ");
                clear_buffer(); // clear invalid input
            } else {
                break; // valid input
            }
        }
    }
}

// Function to demonstrate binary search
void demonstrate_binary_search() {
    int size = 0;
    printf("Enter the size of the sorted array: ");
    while (1) {
        if (scanf("%d", &size) != 1 || size <= 0) {
            printf("Invalid size. Please enter a positive integer: ");
            clear_buffer();
        } else {
            clear_buffer(); // Clear the input buffer after reading a valid size
            break;
        }
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    input_sorted_array(arr, size);

    int target = 0;
    printf("Enter the integer to search for: ");
    while (1) {
        if (scanf("%d", &target) != 1) {
            printf("Invalid input. Please enter an integer: ");
            clear_buffer();
        } else {
            break;
        }
    }

    int result = binary_search(arr, 0, size - 1, target);
    
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    free(arr); // Free allocated memory
}

// Main function where the program starts
int main() {
    printf("Welcome to the Binary Search Program!\n");
    char continue_program;

    do {
        demonstrate_binary_search();

        printf("Do you want to search another number? (y/n): ");
        scanf(" %c", &continue_program);
        clear_buffer(); // Clear input buffer

    } while (continue_program == 'y' || continue_program == 'Y');

    printf("Thank you for using the program. Goodbye!\n");
    return 0;
}