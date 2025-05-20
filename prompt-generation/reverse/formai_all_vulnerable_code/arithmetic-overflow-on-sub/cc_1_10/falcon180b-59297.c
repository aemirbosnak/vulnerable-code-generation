//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int n;

void generateArray(int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void printArray(int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    generateArray(size);
    printf("Original array:\n");
    printArray(size);

    quickSort(arr, 0, size-1);
    printf("Sorted array:\n");
    printArray(size);

    return 0;
}