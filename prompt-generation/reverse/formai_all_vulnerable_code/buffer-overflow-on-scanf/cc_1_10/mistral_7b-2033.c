//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to check if an array is empty
bool is_empty(int arr[], int size) {
    if (size <= 0) {
        printf("Error: Array is empty.\n");
        exit(EXIT_FAILURE);
    }
    return false;
}

// Function to display the elements of an array
void display_array(const char *msg, int arr[], int size) {
    if (size > 0) {
        printf("%s:", msg);
        for (int i = 0; i < size; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }
}

// Function to perform bubble sort
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    int size, arr[MAX_SIZE];

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the array is empty
    is_empty(arr, size);

    // Input the elements of the array
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the unsorted array
    printf("\nUnsorted Array:\n");
    display_array("Unsorted: ", arr, size);

    // Perform bubble sort
    bubble_sort(arr, size);

    // Display the sorted array
    printf("\nSorted Array:\n");
    display_array("Sorted: ", arr, size);

    return EXIT_SUCCESS;
}