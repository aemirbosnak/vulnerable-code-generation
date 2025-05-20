//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Function to compare two integers
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Function to print the array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the size of the array from the user
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the size is valid
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Allocate memory for the array
    int *arr = malloc(size * sizeof(int));

    // Check if the memory was allocated successfully
    if (arr == NULL) {
        printf("Failed to allocate memory for the array.\n");
        return 1;
    }

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using the qsort function
    qsort(arr, size, sizeof(int), compare);

    // Print the sorted array
    printf("The sorted array is: ");
    print_array(arr, size);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}