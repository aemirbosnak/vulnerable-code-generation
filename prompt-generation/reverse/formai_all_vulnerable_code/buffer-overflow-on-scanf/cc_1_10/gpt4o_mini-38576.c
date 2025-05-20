//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int* arr, int size);
void printArray(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
void insertionSort(int* arr, int size);
void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

// Main function
int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    // Dynamic memory allocation for the array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generate a random array
    generateRandomArray(arr, size);
    
    printf("Generated Array:\n");
    printArray(arr, size);

    // Bubble Sort
    int* arrBubble = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrBubble[i] = arr[i];
    }

    printf("\nSorting using Bubble Sort:\n");
    bubbleSort(arrBubble, size);
    printArray(arrBubble, size);
    
    free(arrBubble);

    // Selection Sort
    int* arrSelection = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrSelection[i] = arr[i];
    }

    printf("\nSorting using Selection Sort:\n");
    selectionSort(arrSelection, size);
    printArray(arrSelection, size);
    
    free(arrSelection);

    // Insertion Sort
    int* arrInsertion = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrInsertion[i] = arr[i];
    }

    printf("\nSorting using Insertion Sort:\n");
    insertionSort(arrInsertion, size);
    printArray(arrInsertion, size);
    
    free(arrInsertion);

    // Merge Sort
    printf("\nSorting using Merge Sort:\n");
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);

    free(arr);
    return 0;
}

// Function to generate a random array
void generateRandomArray(int* arr, int size) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print the array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort Implementation
void bubbleSort(int* arr, int size) {
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

// Selection Sort Implementation
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort Implementation
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort Implementation
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Merge function for Merge Sort
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* leftArray = (int*)malloc(n1 * sizeof(int));
    int* rightArray = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArray[] (if any)
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArray[] (if any)
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(leftArray);
    free(rightArray);
}