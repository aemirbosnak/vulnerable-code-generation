//Falcon-180B DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

typedef struct {
    int *arr;
    int size;
} Array;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Array *arr, int low, int high) {
    int pivot = arr->arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr->arr[j] < pivot) {
            i++;
            swap(&arr->arr[i], &arr->arr[j]);
        }
    }

    swap(&arr->arr[i + 1], &arr->arr[high]);
    return i + 1;
}

void quickSort(Array *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Array *arr) {
    int i;
    for (i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
}

int main() {
    int n, i;
    int *arr;
    Array array;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        return 0;
    }

    array.arr = arr;
    array.size = n;

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");
    printArray(&array);

    quickSort(&array, 0, n - 1);

    printf("After sorting:\n");
    printArray(&array);

    free(arr);
    return 0;
}