//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int arr[MAX_SIZE];
    int size;
} Array;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(Array *arr, int low, int high) {
    int pivot = arr->arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr->arr[j] <= pivot) {
            i++;
            swap(&arr->arr[i], &arr->arr[j]);
        }
    }
    swap(&arr->arr[i + 1], &arr->arr[high]);
    return (i + 1);
}

void quickSort(Array *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Array arr;
    arr.size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);

    if (arr.size > MAX_SIZE) {
        printf("Array size too large!\n");
        return 1;
    }

    printf("Initializing array with random values:\n");
    for (int i = 0; i < arr.size; i++) {
        arr.arr[i] = rand() % 100;
    }

    printArray(&arr);
    quickSort(&arr, 0, arr.size - 1);
    printf("Sorted array:\n");
    printArray(&arr);

    return 0;
}