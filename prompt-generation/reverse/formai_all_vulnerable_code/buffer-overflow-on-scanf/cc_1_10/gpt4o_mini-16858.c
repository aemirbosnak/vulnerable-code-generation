//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Function prototypes
void displayMenu();
void inputArray(int arr[], int *size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void displayArray(int arr[], int size);
void copyArray(int source[], int destination[], int size);

int main() {
    int arr[MAX_ITEMS];
    int tempArr[MAX_ITEMS];
    int size = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &size);
                break;
            case 2:
                copyArray(arr, tempArr, size);
                bubbleSort(tempArr, size);
                printf("Sorted using Bubble Sort:\n");
                displayArray(tempArr, size);
                break;
            case 3:
                copyArray(arr, tempArr, size);
                selectionSort(tempArr, size);
                printf("Sorted using Selection Sort:\n");
                displayArray(tempArr, size);
                break;
            case 4:
                copyArray(arr, tempArr, size);
                insertionSort(tempArr, size);
                printf("Sorted using Insertion Sort:\n");
                displayArray(tempArr, size);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Sorting Program Menu ---\n");
    printf("1. Input Array\n");
    printf("2. Sort using Bubble Sort\n");
    printf("3. Sort using Selection Sort\n");
    printf("4. Sort using Insertion Sort\n");
    printf("5. Exit\n");
}

void inputArray(int arr[], int *size) {
    printf("Enter number of elements (max %d): ", MAX_ITEMS);
    scanf("%d", size);

    if (*size > MAX_ITEMS) {
        printf("Size exceeds maximum limit. Setting size to %d.\n", MAX_ITEMS);
        *size = MAX_ITEMS;
    }

    printf("Input elements:\n");
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

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

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}