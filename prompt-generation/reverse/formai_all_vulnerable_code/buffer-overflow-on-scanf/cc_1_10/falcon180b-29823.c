//Falcon-180B DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void input_array(int *arr, int size);
void display_array(int *arr, int size);
void bubble_sort(int *arr, int size);
void swap(int *arr, int i, int j);

int main() {
    int size;
    int *arr = NULL;

    // Prompt the user for the array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Prompt the user to input the array elements
    printf("Enter the array elements:\n");
    input_array(arr, size);

    // Display the unsorted array
    printf("Unsorted array:\n");
    display_array(arr, size);

    // Sort the array using bubble sort
    bubble_sort(arr, size);

    // Display the sorted array
    printf("Sorted array:\n");
    display_array(arr, size);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}

// Function to input the array elements
void input_array(int *arr, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// Function to display the array elements
void display_array(int *arr, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Function to sort the array using bubble sort
void bubble_sort(int *arr, int size) {
    int i, j, temp;
    bool swapped;

    do {
        swapped = false;

        for (i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                swapped = true;
            }
        }

    } while (swapped);
}

// Function to swap two elements of the array
void swap(int *arr, int i, int j) {
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}