//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: modular
// Header Files
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_SIZE 100

// Function Declarations
int get_input(int *arr, int size);
void print_array(int *arr, int size);
void sort_array(int *arr, int size);
void swap(int *a, int *b);

// Main Function
int main() {
    // Variables
    int arr[MAX_SIZE];
    int size;

    // Get the input array
    size = get_input(arr, MAX_SIZE);

    // Print the original array
    printf("Original Array:\n");
    print_array(arr, size);

    // Sort the array
    sort_array(arr, size);

    // Print the sorted array
    printf("Sorted Array:\n");
    print_array(arr, size);

    return 0;
}

// Function to get the input array
int get_input(int *arr, int size) {
    // Variables
    int i;

    // Get the size of the array
    printf("Enter the size of the array (max %d): ", size);
    scanf("%d", &size);

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Return the size of the array
    return size;
}

// Function to print the array
void print_array(int *arr, int size) {
    // Variables
    int i;

    // Print the elements of the array
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Newline
    printf("\n");
}

// Function to sort the array
void sort_array(int *arr, int size) {
    // Variables
    int i, j;

    // Sort the array using the bubble sort algorithm
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to swap two integers
void swap(int *a, int *b) {
    // Variables
    int temp;

    // Swap the two integers
    temp = *a;
    *a = *b;
    *b = temp;
}