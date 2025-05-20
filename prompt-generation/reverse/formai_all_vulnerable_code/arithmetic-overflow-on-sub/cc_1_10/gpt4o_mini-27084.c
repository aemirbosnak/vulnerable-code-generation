//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n, choice;

    // Seed random number generator
    srand(time(NULL));

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Generated array: ");
    printArray(array, n);

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(array, n);
            printf("Array sorted using Bubble Sort: ");
            break;
        case 2:
            selectionSort(array, n);
            printf("Array sorted using Selection Sort: ");
            break;
        case 3:
            insertionSort(array, n);
            printf("Array sorted using Insertion Sort: ");
            break;
        default:
            printf("Invalid choice!\n");
            free(array);
            return 1;
    }

    printArray(array, n);
    free(array);
    return 0;
}