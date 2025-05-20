//Falcon-180B DATASET v1.0 Category: Recursive ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to reverse an array
void reverseArray(int arr[], int start, int end) {
    int temp;
    if (start >= end) {
        return;
    }

    // Swap the elements at the start and end positions
    temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursively reverse the sub-array from start+1 to end-1
    reverseArray(arr, start+1, end-1);
}

// Function to generate a random array of integers
void generateRandomArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *) malloc(size * sizeof(int));

    // Generate a random array of integers
    generateRandomArray(arr, size);

    // Print the original array
    printf("Original array:\n");
    printArray(arr, size);

    // Reverse the array using a recursive function
    reverseArray(arr, 0, size-1);

    // Print the reversed array
    printf("Reversed array:\n");
    printArray(arr, size);

    // Free the dynamically allocated memory
    free(arr);
    return 0;
}