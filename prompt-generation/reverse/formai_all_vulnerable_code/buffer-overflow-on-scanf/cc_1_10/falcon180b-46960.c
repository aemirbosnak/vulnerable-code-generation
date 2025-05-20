//Falcon-180B DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to print an array in reverse order
void printReverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to reverse an array
void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    // Swap the first and last elements
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursively reverse the rest of the array
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array:\n");
    printReverse(arr, size);

    // Reverse the array using recursion
    reverseArray(arr, 0, size - 1);

    // Print the reversed array
    printf("Reversed array:\n");
    printReverse(arr, size);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}