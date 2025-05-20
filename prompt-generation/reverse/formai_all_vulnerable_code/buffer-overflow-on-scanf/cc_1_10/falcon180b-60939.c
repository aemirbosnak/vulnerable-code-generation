//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate random numbers between 0 and 100
int generateRandomNumber() {
    return rand() % 101;
}

// Function to swap two elements in an array
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
    int arr[MAX_SIZE];
    int n;

    // Get the size of the array from user input
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Generate random numbers for the array
    srand(time(NULL));
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = generateRandomNumber();
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}