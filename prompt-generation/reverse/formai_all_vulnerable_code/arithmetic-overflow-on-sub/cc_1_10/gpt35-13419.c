//FormAI DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE], n, i, choice;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Array after bubble sort:\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("Array after selection sort:\n");
            break;
        case 3:
            insertionSort(arr, n);
            printf("Array after insertion sort:\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/**
 * Bubble sort algorithm
 * @param arr The array to be sorted
 * @param n   The size of the array
 */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * Selection sort algorithm
 * @param arr The array to be sorted
 * @param n   The size of the array
 */
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/**
 * Insertion sort algorithm
 * @param arr The array to be sorted
 * @param n   The size of the array
 */
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