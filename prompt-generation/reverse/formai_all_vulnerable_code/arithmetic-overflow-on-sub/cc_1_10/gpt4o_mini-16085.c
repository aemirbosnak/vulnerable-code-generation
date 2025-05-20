//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Bubble Sort Implementation
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Selection Sort Implementation
void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// Insertion Sort Implementation
void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Function to get array from user
int* getUserInput(int *size) {
    printf("Enter the number of elements: ");
    scanf("%d", size);
    int *array = (int*)malloc((*size) * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &array[i]);
    }
    return array;
}

int main() {
    int size;
    int *array = getUserInput(&size);
    
    printf("Original array: ");
    printArray(array, size);

    int choice;
    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(array, size);
            printf("Sorted array using Bubble Sort: ");
            printArray(array, size);
            break;
        case 2:
            selectionSort(array, size);
            printf("Sorted array using Selection Sort: ");
            printArray(array, size);
            break;
        case 3:
            insertionSort(array, size);
            printf("Sorted array using Insertion Sort: ");
            printArray(array, size);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            free(array);
            return 1;
    }

    // Free allocated memory
    free(array);
    return 0;
}