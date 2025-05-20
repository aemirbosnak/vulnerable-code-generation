//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    int choice;
    int size, i;
    printf("Welcome to the Cryptic Sorting Arena!\n");
    printf("Enter the number of elements you wish to sort: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose sorting method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have chosen Bubble Sort!\n");
            bubbleSort(arr, size);
            break;
        case 2:
            printf("Selection Sort: Let the games begin!\n");
            selectionSort(arr, size);
            break;
        case 3:
            printf("Inserting order with Insertion Sort!\n");
            insertionSort(arr, size);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            free(arr);
            return -1;
    }

    printf("The sorted array is:\n");
    printArray(arr, size);
    
    free(arr);
    return 0;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}