//Falcon-180B DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

typedef struct {
    int *array;
    int size;
} Array;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    // Partition
    while (i <= j) {
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    // Recursion
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    Array array;
    int i;

    srand(time(NULL));

    array.array = (int *)malloc(MAX_SIZE * sizeof(int));
    array.size = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        int randNum = rand() % 100;
        array.array[array.size] = randNum;
        array.size++;
    }

    printf("Before sorting:\n");
    printArray(array.array, array.size);

    quickSort(array.array, 0, array.size - 1);

    printf("After sorting:\n");
    printArray(array.array, array.size);

    free(array.array);
    return 0;
}