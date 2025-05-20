//Falcon-180B DATASET v1.0 Category: Recursive ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to print an array in reverse order
void printArrayReverse(int arr[], int size) {
    if (size == 0)
        return;

    // Recursive call to print the last element
    printArrayReverse(arr, size - 1);

    // Print the current element
    printf("%d ", arr[size - 1]);
}

// Function to add two arrays
void addArrays(int arr1[], int arr2[], int size) {
    if (size == 0)
        return;

    // Recursive call to add the last element
    addArrays(arr1, arr2, size - 1);

    // Add the current element and store the result in the first array
    arr1[size - 1] += arr2[size - 1];
}

// Function to multiply two arrays
void multiplyArrays(int arr1[], int arr2[], int size) {
    if (size == 0)
        return;

    // Recursive call to multiply the last element
    multiplyArrays(arr1, arr2, size - 1);

    // Multiply the current element and store the result in the first array
    arr1[size - 1] *= arr2[size - 1];
}

int main() {
    int arr1[100], arr2[100], size;

    // Get the size of the arrays
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    // Get the elements of the first array
    printf("Enter the elements of the first array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr1[i]);
    }

    // Get the elements of the second array
    printf("Enter the elements of the second array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr2[i]);
    }

    // Print the first array in reverse order
    printf("The first array in reverse order is: ");
    printArrayReverse(arr1, size);
    printf("\n");

    // Add the two arrays
    printf("The sum of the two arrays is: ");
    addArrays(arr1, arr2, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Multiply the two arrays
    printf("The product of the two arrays is: ");
    multiplyArrays(arr1, arr2, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}