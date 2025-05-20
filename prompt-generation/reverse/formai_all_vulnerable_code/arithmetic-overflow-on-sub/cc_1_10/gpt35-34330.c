//FormAI DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, i, option;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Select a sorting algorithm: \n1. Bubble Sort\n2. Insertion Sort\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            bubbleSort(arr, n);
            printf("Sorted array using Bubble Sort: \n");
            printArray(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            printf("Sorted array using Insertion Sort: \n");
            printArray(arr, n);
            break;
        default:
            printf("Invalid option selected!\n");
            break;
    }
    return 0;
}