//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

// Function prototypes
void displayMenu();
void generateRandomArray(int arr[], int size);
void displayArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// Main interactive function
int main() {
    int choice, size;
    int arr[MAX_SIZE];

    // Seed the random number generator
    srand(time(0));
    
    printf("Welcome to the Visionary Sorting Program!\n");
    displayMenu();

    while (1) {
        printf("\nEnter your choice (1-5 for sorting, 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Visionary Sorting Program. Goodbye!\n");
            break;
        }

        printf("Enter the number of elements (max %d): ", MAX_SIZE);
        scanf("%d", &size);
        if (size < 1 || size > MAX_SIZE) {
            printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
            continue;
        }

        generateRandomArray(arr, size);
        printf("Generated Array:\n");
        displayArray(arr, size);

        switch (choice) {
            case 1:
                bubbleSort(arr, size);
                printf("Sorted Array using Bubble Sort:\n");
                break;
            case 2:
                selectionSort(arr, size);
                printf("Sorted Array using Selection Sort:\n");
                break;
            case 3:
                insertionSort(arr, size);
                printf("Sorted Array using Insertion Sort:\n");
                break;
            case 4:
                quickSort(arr, 0, size - 1);
                printf("Sorted Array using Quick Sort:\n");
                break;
            default:
                printf("Invalid choice! Please select a valid sorting option.\n");
                continue;
        }
        displayArray(arr, size);
    }

    return 0;
}

// Function to display the menu with sorting options
void displayMenu() {
    printf("Please choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("0. Exit\n");
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // random numbers between 0 and 99
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort implementation
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Insertion Sort implementation
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}