//Falcon-180B DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to print an array in reverse order
void printArrayReverse(int arr[], int size) {
    if (size == 0 || size == 1) {
        printf("Array is empty or has only one element.\n");
        return;
    }
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to reverse an array using recursion
void reverseArray(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    reverseArray(arr, 0, size - 1);
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printArrayReverse(arr, size);
    return 0;
}