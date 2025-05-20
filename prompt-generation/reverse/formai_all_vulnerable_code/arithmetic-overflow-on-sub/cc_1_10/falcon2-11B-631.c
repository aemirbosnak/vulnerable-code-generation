//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2];
        partition(arr, low, high);
        quicksort(arr, low, (pivot - 1));
        quicksort(arr, (pivot + 1), high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    srand(time(NULL));
    int arr[n];

    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting:\n");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Array after sorting:\n");
    printArray(arr, n);

    return 0;
}