//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the array for sorting
#define MIN_NUM 1 // Minimum number for the random number generation
#define MAX_NUM 100 // Maximum number for the random number generation

// Function to print the array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform the Bubble Sort
void bubbleSort(int arr[], int size) {
    int temp;
    int swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0; // Flag to check if any swapping occurred
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Mark that a swap occurred
            }
        }
        if (swapped == 0) { // If no swapping occurred, the array is sorted
            break; 
        }
    }
}

// Function to perform the Selection Sort
void selectionSort(int arr[], int size) {
    int minIndex, temp;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i; // Assume the current index is the smallest
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update the index of the smallest element
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform the Insertion Sort
void insertionSort(int arr[], int size) {
    int key, j;

    for (int i = 1; i < size; i++) {
        key = arr[i]; // Element to be inserted
        j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place the key in its correct position
    }
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM; // Random number between MIN_NUM and MAX_NUM
    }
}

int main() {
    int arr[SIZE];
    int choice;

    // Generate an array with random numbers
    generateRandomArray(arr, SIZE);

    // Print the original array
    printArray(arr, SIZE);

    // User chooses the sorting algorithm
    printf("Choose the sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, SIZE);
            printf("Array sorted using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(arr, SIZE);
            printf("Array sorted using Selection Sort:\n");
            break;
        case 3:
            insertionSort(arr, SIZE);
            printf("Array sorted using Insertion Sort:\n");
            break;
        default:
            printf("Invalid choice! Exiting program.\n");
            return 1;
    }

    // Print the sorted array
    printArray(arr, SIZE);
    return 0;
}