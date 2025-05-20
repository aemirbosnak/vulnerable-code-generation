//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function prototypes
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void menu();

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    int arr[MAX_SIZE];
    int size, choice;

    menu();
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if (size < 1 || size > MAX_SIZE) {
        fprintf(stderr, "Error: Size must be between 1 and %d\n", MAX_SIZE);
        return EXIT_FAILURE;
    }

    generateRandomArray(arr, size);
    printf("Generated Array:\n");
    printArray(arr, size);

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            printf("Array sorted using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(arr, size);
            printf("Array sorted using Selection Sort:\n");
            break;
        case 3:
            insertionSort(arr, size);
            printf("Array sorted using Insertion Sort:\n");
            break;
        case 4:
            printf("Exiting the program.\n");
            return EXIT_SUCCESS;
        default:
            fprintf(stderr, "Error: Invalid choice\n");
            return EXIT_FAILURE;
    }

    printArray(arr, size);
    return EXIT_SUCCESS;
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

// Bubble Sort implementation
void bubbleSort(int arr[], int size) {
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

// Selection Sort implementation
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort implementation
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

// Menu function to display instructions
void menu() {
    printf("Welcome to the Sorting Program!\n");
    printf("You can generate a random array and sort it using different algorithms.\n");
}