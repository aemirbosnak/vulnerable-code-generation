//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function Prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
int inputArray(int arr[], int size);
void swap(int* a, int* b);

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Welcome to the QuickSort Program!\n");
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    
    // Input the number of elements
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Invalid input! Please enter a number between 1 and %d: ", MAX_SIZE);
        while(getchar() != '\n'); // clear input buffer
    }

    // Input the elements of the array
    printf("Please enter %d integers:\n", n);
    if (!inputArray(arr, n)) {
        printf("Error reading the input values. Exiting the program.\n");
        return 1;
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Timing the QuickSort algorithm
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %f seconds\n", time_spent);

    return 0;
}

// Function to perform QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array
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

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to read the array elements
int inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            while(getchar() != '\n'); // clear input buffer
            return 0; // Error occurred
        }
    }
    return 1; // Success
}

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}