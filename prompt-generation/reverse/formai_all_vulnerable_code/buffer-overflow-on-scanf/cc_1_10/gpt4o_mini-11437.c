//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function Prototypes
void fillArray(int *arr, int size);
void printArray(const int *arr, int size);
void bubbleSort(int *arr, int size);
void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);
void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

// Main function
int main() {
    srand(time(NULL)); // Seed for randomness
    int arr[MAX_SIZE];
    int size;

    // Input size of array
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Fill the array with random numbers and print it
    fillArray(arr, size);
    printf("Original Array:\n");
    printArray(arr, size);

    // Sort using Bubble Sort
    printf("\nSorting using Bubble Sort...\n");
    bubbleSort(arr, size);
    printf("Sorted Array (Bubble Sort):\n");
    printArray(arr, size);

    // Refill the array for the next sort
    fillArray(arr, size);
    printf("\nOriginal Array (Refilled for next sort):\n");
    printArray(arr, size);

    // Sort using Merge Sort
    printf("\nSorting using Merge Sort...\n");
    mergeSort(arr, 0, size - 1);
    printf("Sorted Array (Merge Sort):\n");
    printArray(arr, size);

    // Refill the array for the next sort
    fillArray(arr, size);
    printf("\nOriginal Array (Refilled for next sort):\n");
    printArray(arr, size);

    // Sort using Quick Sort
    printf("\nSorting using Quick Sort...\n");
    quickSort(arr, 0, size - 1);
    printf("Sorted Array (Quick Sort):\n");
    printArray(arr, size);

    return 0;
}

// Function to fill the array with random numbers
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0-99
    }
}

// Function to print the array
void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort implementation
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge Sort implementation
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Quick Sort implementation
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}