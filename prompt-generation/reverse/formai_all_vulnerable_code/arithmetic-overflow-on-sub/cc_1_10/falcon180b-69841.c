//Falcon-180B DATASET v1.0 Category: Sorting ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void swap(element *arr, int i, int j) {
    element temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(element *arr, int low, int high) {
    element pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].data < pivot.data) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quicksort(element *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

void printarray(element *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    element arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }
    printf("Before sorting:\n");
    printarray(arr, size);
    quicksort(arr, 0, size - 1);
    printf("After sorting:\n");
    printarray(arr, size);
    return 0;
}