//Falcon-180B DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} Array;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateArray(Array *array) {
    srand(time(NULL));
    array->data = (int *) malloc(MAX_SIZE * sizeof(int));
    array->size = rand() % MAX_SIZE + 1;
    for (int i = 0; i < array->size; i++) {
        array->data[i] = rand() % 100;
    }
}

void merge(int *arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    Array array;
    generateArray(&array);
    int *arr = array.data;
    int size = array.size;

    printf("Original Array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted Array:\n");
    printArray(arr, size);

    return 0;
}