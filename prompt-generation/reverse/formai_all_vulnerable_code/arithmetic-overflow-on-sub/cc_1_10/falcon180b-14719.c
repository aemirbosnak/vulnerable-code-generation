//Falcon-180B DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of an array in reverse order
void printArrayReverse(int arr[], int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to reverse the elements of an array
void reverseArray(int arr[], int size) {
    int i;
    for (i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Main function to test the above functions
int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array dynamically
    int *arr = (int *)malloc(size * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array:\n");
    printArrayReverse(arr, size);

    // Reverse the array using the recursive function
    reverseArray(arr, size);

    // Print the reversed array
    printf("Reversed array:\n");
    printArrayReverse(arr, size);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}