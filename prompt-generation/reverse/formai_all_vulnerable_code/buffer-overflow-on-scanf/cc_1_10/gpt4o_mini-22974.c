//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 100

// Function prototypes
void generateRandomArray(int *array, int size);
void printArray(int *array, int size);
void bubbleSort(int *array, int size);
void selectionSort(int *array, int size);
void insertionSort(int *array, int size);
void swap(int *a, int *b);
void menu();

int main() {
    int array[MAX_ELEMENTS];
    int size = 0;
    int choice;

    printf("Welcome to the Curious Sorting Program!\n");
    printf("How many numbers do you want to sort (1 to 100)? ");
    scanf("%d", &size);

    if (size < 1 || size > MAX_ELEMENTS) {
        printf("Invalid size! Exiting program.\n");
        return 1;
    }

    generateRandomArray(array, size);
    printf("Generated Array:\n");
    printArray(array, size);

    menu();

    printf("Enter your choice of sorting method: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(array, size);
            printf("Array sorted using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(array, size);
            printf("Array sorted using Selection Sort:\n");
            break;
        case 3:
            insertionSort(array, size);
            printf("Array sorted using Insertion Sort:\n");
            break;
        default:
            printf("Invalid choice! Exiting program.\n");
            return 1;
    }

    printArray(array, size);
    printf("Thank you for using the Curious Sorting Program! Goodbye!\n");
    return 0;
}

void generateRandomArray(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(&array[i], &array[minIndex]);
    }
}

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

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void menu() {
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
}