//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Function to generate a random number between 0 and n-1
int randInt(int n) {
    return rand() % n;
}

// Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform bitwise operations on an array
void bitwiseOps(int arr[], int n) {
    int i;
    int sum = 0;
    int product = 1;
    int xorResult = 0;

    // Perform bitwise OR operation on all elements
    for (i = 0; i < n; i++) {
        sum |= arr[i];
    }
    printf("Sum of all elements using bitwise OR: %d\n", sum);

    // Perform bitwise AND operation on all elements
    for (i = 0; i < n; i++) {
        product &= arr[i];
    }
    printf("Product of all elements using bitwise AND: %d\n", product);

    // Perform bitwise XOR operation on all elements
    for (i = 0; i < n; i++) {
        xorResult ^= arr[i];
    }
    printf("XOR of all elements using bitwise XOR: %d\n", xorResult);
}

int main() {
    int i, n;

    // Get the number of elements from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate random numbers and store them in an array
    int arr[SIZE];
    for (i = 0; i < n; i++) {
        arr[i] = randInt(100);
    }

    // Sort the array in ascending order
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform bitwise operations on the array
    bitwiseOps(arr, n);

    return 0;
}