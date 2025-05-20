//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
int menu();

// Main function
int main() {
    int choice, size;
    
    printf("Welcome to the Simple Sorting Program!\n");
    printf("Please enter the number of elements you want to sort: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Please enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    do {
        choice = menu();
        
        switch (choice) {
            case 1:
                printf("You chose Bubble Sort:\n");
                bubbleSort(arr, size);
                printArray(arr, size);
                break;
            case 2:
                printf("You chose Selection Sort:\n");
                selectionSort(arr, size);
                printArray(arr, size);
                break;
            case 3:
                printf("You chose Insertion Sort:\n");
                insertionSort(arr, size);
                printArray(arr, size);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                free(arr);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (true);
    
    free(arr);
    return 0;
}

// Print the array
void printArray(int arr[], int size) {
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble sort algorithm
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size-1; i++) {
        swapped = false;
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// Selection sort algorithm
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion sort algorithm
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Menu function
int menu() {
    int choice;
    printf("\nSorting Algorithms:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}