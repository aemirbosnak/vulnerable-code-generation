//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100

// Function to fill an array with random integers
void fillArrayWithRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform insertion sort
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

// Main program
int main() {
    srand(time(0)); // Seed for random number generation

    int arr[MAX_ARRAY_SIZE];
    int size;

    printf("Enter the number of elements (max %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &size);

    if(size <= 0 || size > MAX_ARRAY_SIZE){
        printf("Invalid size. Please enter a number between 1 and %d.\n", MAX_ARRAY_SIZE);
        return 1;
    }

    // Fill array with random numbers
    fillArrayWithRandomNumbers(arr, size);
    
    printf("Original array:\n");
    printArray(arr, size);

    // Perform bubble sort
    int bubbleSortedArray[MAX_ARRAY_SIZE];
    for (int i = 0; i < size; i++) {
        bubbleSortedArray[i] = arr[i];
    }
    
    bubbleSort(bubbleSortedArray, size);
    printf("Array sorted using Bubble Sort:\n");
    printArray(bubbleSortedArray, size);

    // Perform selection sort
    int selectionSortedArray[MAX_ARRAY_SIZE];
    for (int i = 0; i < size; i++) {
        selectionSortedArray[i] = arr[i];
    }

    selectionSort(selectionSortedArray, size);
    printf("Array sorted using Selection Sort:\n");
    printArray(selectionSortedArray, size);

    // Perform insertion sort
    int insertionSortedArray[MAX_ARRAY_SIZE];
    for (int i = 0; i < size; i++) {
        insertionSortedArray[i] = arr[i];
    }

    insertionSort(insertionSortedArray, size);
    printf("Array sorted using Insertion Sort:\n");
    printArray(insertionSortedArray, size);

    printf("Sorting program completed successfully!\n");

    return 0;
}