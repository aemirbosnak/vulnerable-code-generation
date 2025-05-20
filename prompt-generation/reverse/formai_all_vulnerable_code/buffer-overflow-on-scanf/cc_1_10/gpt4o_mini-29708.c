//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100
#define MIN_RANDOM_VALUE 1
#define MAX_RANDOM_VALUE 1000

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void randomizeArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (MAX_RANDOM_VALUE - MIN_RANDOM_VALUE + 1)) + MIN_RANDOM_VALUE;
    }
}

int main() {
    int arr[MAX_ELEMENTS];
    int choice, size;

    printf("Welcome to the Sorting Program!\n");
    printf("Enter the number of elements (1 to %d): ", MAX_ELEMENTS);
    scanf("%d", &size);
  
    if (size < 1 || size > MAX_ELEMENTS) {
        printf("Invalid number of elements! Please run the program again.\n");
        return 1;
    }

    randomizeArray(arr, size);
    printf("Generated Random Array: ");
    printArray(arr, size);

    printf("\nChoose the sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Quick Sort\n");
    printf("Enter your choice (1, 2 or 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            printf("Sorted Array using Bubble Sort: ");
            break;
        case 2:
            insertionSort(arr, size);
            printf("Sorted Array using Insertion Sort: ");
            break;
        case 3:
            quickSort(arr, 0, size - 1);
            printf("Sorted Array using Quick Sort: ");
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            return 1;
    }

    printArray(arr, size);

    return 0;
}