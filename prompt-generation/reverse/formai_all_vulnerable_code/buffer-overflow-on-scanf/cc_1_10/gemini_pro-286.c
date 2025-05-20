//GEMINI-pro DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the data type of the array
typedef int data_type;

// Create the array
data_type arr[MAX_SIZE];

// Function to generate random numbers
void generate_random_numbers(int n) {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate random numbers and store them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the array
void print_array(int n) {
    // Print the array elements
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Print a newline character
    printf("\n");
}

// Function to sort the array in ascending order
void sort_array(int n) {
    // Sort the array using the bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the two elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to search for an element in the array
int search_element(int n, int element) {
    // Search for the element using the linear search algorithm
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }

    // Return -1 if the element is not found
    return -1;
}

// Main function
int main() {
    // Get the number of elements in the array from the user
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Generate random numbers and store them in the array
    generate_random_numbers(n);

    // Print the original array
    printf("Original array: ");
    print_array(n);

    // Sort the array in ascending order
    sort_array(n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(n);

    // Get the element to search for from the user
    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    // Search for the element in the array
    int index = search_element(n, element);

    // Print the result of the search
    if (index == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}