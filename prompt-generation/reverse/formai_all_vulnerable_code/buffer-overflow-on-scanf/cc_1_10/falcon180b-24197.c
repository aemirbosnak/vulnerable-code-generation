//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate random numbers
int rand(void) {
    return rand() % 100;
}

// Function to swap two numbers without using a third variable
void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// Function to sort an array using bubble sort algorithm
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

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, i;

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Initialize the array with random numbers
    int arr[n];
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Sort the array
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}