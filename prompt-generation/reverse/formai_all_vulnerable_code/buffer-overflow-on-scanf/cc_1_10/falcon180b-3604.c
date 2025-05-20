//Falcon-180B DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[low + (high - low) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quickSort(arr, low, j);
    if (i < high)
        quickSort(arr, i, high);
}

void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size < 1) {
        printf("Invalid array size.\n");
        return 0;
    }

    generateRandomArray(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}