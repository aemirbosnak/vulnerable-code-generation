//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100
#define SORTING_ALGORITHM 2

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort an array using selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr, min_idx, i);
    }
}

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice = 0;

    // Print menu to select sorting algorithm
    printf("Sorting Algorithm Menu:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call sorting function based on user choice
    switch (choice) {
        case 1: selectionSort(arr, n); break;
        case 2: bubbleSort(arr, n); break;
        case 3: insertionSort(arr, n); break;
        default: printf("Invalid input. Please try again.\n");
    }

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}