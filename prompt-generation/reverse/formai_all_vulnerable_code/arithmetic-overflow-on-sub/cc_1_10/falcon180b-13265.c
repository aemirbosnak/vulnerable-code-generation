//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>

// Define the maximum number of elements to be sorted
#define MAX_ELEMENTS 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the bubble sort algorithm
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        // If no two elements were swapped by inner loop, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_ELEMENTS], n;

    // Get the number of elements to be sorted from the user
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Get the elements to be sorted from the user
    printf("Enter the elements to be sorted: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort algorithm
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}