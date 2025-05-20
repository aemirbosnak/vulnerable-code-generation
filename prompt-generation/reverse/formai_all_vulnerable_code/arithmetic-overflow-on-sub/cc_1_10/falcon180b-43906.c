//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to initialize an array with random numbers
void init_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to sort an array using quicksort
void quicksort(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[low + (high - low) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j) {
        quicksort(arr, low, j);
    }
    if (i < high) {
        quicksort(arr, i, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get array size from user input
    printf("Enter array size (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Initialize array with random numbers
    init_array(arr, size);

    // Sort array using quicksort
    quicksort(arr, 0, size - 1);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}