//Falcon-180B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} element;

void swap(element* arr, int i, int j) {
    element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(element* arr, int low, int high) {
    int pivot = arr[high].data;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i+1;
}

void quicksort(element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

void printarray(element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main(void) {
    element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quicksort(arr, 0, size-1);

    printf("Sorted array:\n");
    printarray(arr, size);

    return 0;
}