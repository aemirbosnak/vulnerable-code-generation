//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
void configureSorting(int arr[], int n, const char *sortType);

int main() {
    int n;
    char sortType[20];

    // Configure array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    // Input elements of the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Choose sorting algorithm
    printf("Choose sorting algorithm (bubble/selection/insertion): ");
    scanf("%s", sortType);

    // Perform the sorting based on user choice
    configureSorting(arr, n, sortType);

    // Free allocated memory
    free(arr);
    return 0;
}

// Function to configure sorting algorithm based on user input
void configureSorting(int arr[], int n, const char *sortType) {
    if (strcmp(sortType, "bubble") == 0) {
        bubbleSort(arr, n);
    } else if (strcmp(sortType, "selection") == 0) {
        selectionSort(arr, n);
    } else if (strcmp(sortType, "insertion") == 0) {
        insertionSort(arr, n);
    } else {
        printf("Invalid sorting algorithm specified.\n");
        return;
    }

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Selection Sort algorithm
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}