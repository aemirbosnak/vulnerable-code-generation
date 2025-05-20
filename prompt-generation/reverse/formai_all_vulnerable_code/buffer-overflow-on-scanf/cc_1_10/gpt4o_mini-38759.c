//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int size);
void swap(int* a, int* b);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void generateRandomArray(int arr[], int size);

// Main function
int main() {
    int choice;
    int size = 10;
    int arr[size];
    
    generateRandomArray(arr, size);

    printf("Original Array: \n");
    printArray(arr, size);

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            printf("\nArray sorted using Bubble Sort:\n");
            printArray(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            printf("\nArray sorted using Selection Sort:\n");
            printArray(arr, size);
            break;
        case 3:
            insertionSort(arr, size);
            printf("\nArray sorted using Insertion Sort:\n");
            printArray(arr, size);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort implementation
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

// Insertion Sort implementation
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