//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

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

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void generateRandomArray(int arr[], int size) {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_ELEMENTS];
    int n;

    // User chooses the number of elements
    printf("Enter the number of elements (1 to %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    if (n < 1 || n > MAX_ELEMENTS) {
        printf("Invalid input! Must be between 1 and %d.\n", MAX_ELEMENTS);
        return 1;
    }

    // Generate and print random array
    generateRandomArray(arr, n);
    printf("Original array: ");
    printArray(arr, n);

    // Make a copy for each sorting algorithm
    int arrBubble[MAX_ELEMENTS], arrSelection[MAX_ELEMENTS], arrInsertion[MAX_ELEMENTS];
    for (int i = 0; i < n; i++) {
        arrBubble[i] = arr[i];
        arrSelection[i] = arr[i];
        arrInsertion[i] = arr[i];
    }

    // Start sorting with Bubble Sort
    printf("Sorting using Bubble Sort...\n");
    bubbleSort(arrBubble, n);
    printf("Sorted array (Bubble Sort): ");
    printArray(arrBubble, n);

    // Start sorting with Selection Sort
    printf("Sorting using Selection Sort...\n");
    selectionSort(arrSelection, n);
    printf("Sorted array (Selection Sort): ");
    printArray(arrSelection, n);
    
    // Start sorting with Insertion Sort
    printf("Sorting using Insertion Sort...\n");
    insertionSort(arrInsertion, n);
    printf("Sorted array (Insertion Sort): ");
    printArray(arrInsertion, n);

    return 0;
}