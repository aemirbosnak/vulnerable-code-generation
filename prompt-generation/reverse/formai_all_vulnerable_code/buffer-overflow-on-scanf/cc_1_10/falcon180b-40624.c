//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to calculate the sum of all elements in an array
unsigned long long int sumArray(int arr[], int size) {
    unsigned long long int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Recursive function to print an array in reverse order
void printArrayReverse(int arr[], int size) {
    if (size == 0) {
        return;
    }
    printArrayReverse(arr, size - 1);
    printf("%d ", arr[size - 1]);
}

// Function to input an array of integers
void inputArray(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Input array size
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Input array elements
    inputArray(arr, size);

    // Print array in reverse order
    printf("Array in reverse order:\n");
    printArrayReverse(arr, size);

    // Calculate sum of array elements
    unsigned long long int sum = sumArray(arr, size);
    printf("\nSum of array elements: %llu\n", sum);

    return 0;
}