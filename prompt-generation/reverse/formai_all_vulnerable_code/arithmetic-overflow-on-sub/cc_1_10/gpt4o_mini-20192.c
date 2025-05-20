//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int n;

    // Seed for random number generation
    srand(time(0));

    printf("Enter number of elements to sort (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    if(n > MAX_SIZE) {
        printf("Number exceeds maximum size of %d. Exiting.\n", MAX_SIZE);
        return 1;
    }

    // Generating random elements
    printf("Generating %d random numbers:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0-999
        printf("%d ", arr[i]);
    }
    printf("\n");

    int choice;
    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Sorting using Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Sorting using Selection Sort...\n");
            selectionSort(arr, n);
            break;
        case 3:
            printf("Sorting using Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}