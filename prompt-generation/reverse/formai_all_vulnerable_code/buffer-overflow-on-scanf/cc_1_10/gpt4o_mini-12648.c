//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort Algorithm
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

// Quick Sort Algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to get user input with error check
int* getInputArray(int *n) {
    printf("Enter the number of elements: ");
    if (scanf("%d", n) != 1 || *n <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    int *arr = malloc(*n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d integers:\n", *n);
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input. Please enter valid integers.\n");
            free(arr);
            exit(EXIT_FAILURE);
        }
    }
    return arr;
}

int main() {
    int n;
    int *arr = getInputArray(&n);

    printf("Choose sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Quick Sort\n");
    int choice;
    
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        fprintf(stderr, "Invalid choice. Please enter 1 for Insertion Sort or 2 for Quick Sort.\n");
        free(arr);
        exit(EXIT_FAILURE);
    }

    switch (choice) {
        case 1:
            insertionSort(arr, n);
            printf("Array sorted using Insertion Sort:\n");
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            printf("Array sorted using Quick Sort:\n");
            break;
    }

    displayArray(arr, n);
    
    free(arr);
    return 0;
}