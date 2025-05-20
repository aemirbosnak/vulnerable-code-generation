//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void printArray(int arr[], int size);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void generateRandomArray(int arr[], int n);

int main() {
    int choice, n;
    int arr[MAX_SIZE];

    printf("Welcome to the C Sorting Program!\n");
    printf("Enter the number of elements you want to sort (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid size. Please restart the program.\n");
        return 1;
    }

    generateRandomArray(arr, n);

    printf("Generated Array:\n");
    printArray(arr, n);

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Array sorted using Bubble Sort:\n");
            printArray(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            printf("Array sorted using Insertion Sort:\n");
            printArray(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            printf("Array sorted using Selection Sort:\n");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice. Please restart the program.\n");
            return 1;
    }

    return 0;
}

void generateRandomArray(int arr[], int n) {
    srand(time(0));  // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 99
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}