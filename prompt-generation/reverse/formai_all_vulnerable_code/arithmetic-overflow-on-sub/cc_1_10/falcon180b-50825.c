//Falcon-180B DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

int main() {
    int arr[MAX_SIZE], size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random numbers for the array
    srand(time(NULL));
    printf("Generating random numbers...\n");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort the array using selection sort
    selectionSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}