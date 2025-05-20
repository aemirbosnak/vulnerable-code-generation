//Falcon-180B DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int size;

    printf("Enter the size of the array (max %d): ", MAX);
    scanf("%d", &size);

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted Array:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted Array:\n");
    printArray(arr, size);

    return 0;
}