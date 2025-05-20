//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
    int n, choice;
    printf("Welcome to the Shape-Shifting Sorting Program!\n");
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nSelect sorting algorithm (1- Bubble Sort, 2- Selection Sort, 3- Insertion Sort): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nYou chose Bubble Sort! Transforming...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("\nYou chose Selection Sort! Transforming...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("\nYou chose Insertion Sort! Transforming...\n");
            insertionSort(arr, n);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            free(arr);
            return 1;
    }

    printf("\nSorted array: \n");
    printArray(arr, n);
    free(arr);
    return 0;
}

// Bubble Sort Implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort Implementation
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort Implementation
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}