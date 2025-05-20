//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int* arr, int size);
void swap(int* a, int* b);
void bubbleSort(int* arr, int size);
void insertionSort(int* arr, int size);
void selectionSort(int* arr, int size);
void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);

// Main function
int main() {
    int *arr = NULL;
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be greater than 0.\n");
        return 1;
    }
    
    // Dynamically allocate memory for the array
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Using Bubble Sort:\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Using Insertion Sort:\n");
            insertionSort(arr, n);
            break;
        case 3:
            printf("Using Selection Sort:\n");
            selectionSort(arr, n);
            break;
        case 4:
            printf("Using Quick Sort:\n");
            quickSort(arr, 0, n - 1);
            break;
        default:
            printf("Invalid choice!\n");
            free(arr);
            return 1;
    }

    // Print sorted array
    printf("Sorted Array:\n");
    printArray(arr, n);

    // Free allocated memory
    free(arr);
    return 0;
}

// Function to print the array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort implementation
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort implementation
void insertionSort(int* arr, int size) {
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

// Selection Sort implementation
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Quick Sort implementation
void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition array for quick sort
int partition(int* arr, int low, int high) {
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