//Falcon-180B DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                arr[k] = arr[i];
                i++;
            } else {
                arr[k] = arr[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            arr[k] = arr[i];
            i++;
            k++;
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("After sorting with Quick Sort:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("After sorting with Merge Sort:\n");
    printArray(arr, size);

    return 0;
}