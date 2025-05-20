//Falcon-180B DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int *data;
    int size;
} Array;

void initArray(Array *arr, int size) {
    arr->data = (int *)malloc(size * sizeof(int));
    arr->size = size;
}

void freeArray(Array *arr) {
    free(arr->data);
}

void printArray(Array arr) {
    int i;
    for (i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Array arr, int low, int high) {
    int pivot = arr.data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr.data[j] < pivot) {
            i++;
            swap(&arr.data[i], &arr.data[j]);
        }
    }

    swap(&arr.data[i + 1], &arr.data[high]);

    return i + 1;
}

void quickSort(Array arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionSort(Array arr) {
    int i, j;
    int key;

    for (i = 1; i < arr.size; i++) {
        key = arr.data[i];
        j = i - 1;

        while (j >= 0 && arr.data[j] > key) {
            arr.data[j + 1] = arr.data[j];
            j--;
        }

        arr.data[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    Array arr;
    initArray(&arr, n);

    srand(time(0));
    int i;
    for (i = 0; i < n; i++) {
        arr.data[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
    printArray(arr);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr);

    freeArray(&arr);

    return 0;
}