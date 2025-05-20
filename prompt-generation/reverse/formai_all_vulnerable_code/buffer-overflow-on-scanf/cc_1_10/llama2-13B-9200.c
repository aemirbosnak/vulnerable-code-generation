//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100
#define SORT_TYPE 0

// Function to print the array elements
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using selection sort
void sort_array(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice = 0;

    // Get the array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random numbers and store them in the array
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Print the unsorted array
    print_array(arr, size);

    // Ask the user to select the sorting type
    printf("Select the sorting type (0 for selection sort, 1 for bubble sort): ");
    scanf("%d", &choice);

    // Sort the array based on the user's selection
    if (choice == 0) {
        sort_array(arr, size);
    } else if (choice == 1) {
        // Implement bubble sort here
        // ...
    } else {
        printf("Invalid selection\n");
        return 1;
    }

    // Print the sorted array
    print_array(arr, size);

    return 0;
}