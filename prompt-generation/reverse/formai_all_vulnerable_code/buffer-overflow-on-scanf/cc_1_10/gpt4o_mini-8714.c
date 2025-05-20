//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, n;

    printf("Welcome to the Sorting Program!\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("The number of elements must be positive!\n");
        return 1;
    }

    int arr[n];
    printf("Enter the elements (separated by spaces): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Your array: ");
    printArray(arr, n);

    printf("\nSorting Options:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Choose a sorting algorithm (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Array sorted using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(arr, n);
            printf("Array sorted using Selection Sort:\n");
            break;
        case 3:
            insertionSort(arr, n);
            printf("Array sorted using Insertion Sort:\n");
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            return 1;
    }

    printArray(arr, n);
    return 0;
}