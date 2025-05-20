//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void initArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    int left[mid], right[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    int i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < mid) {
        arr[k++] = left[i++];
    }
    while (j < size - mid) {
        arr[k++] = right[j++];
    }
}

int main() {
    srand(time(NULL));
    int arr[MAX];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    initArray(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);
    selectionSort(arr, size);
    printf("Sorted array (selection sort):\n");
    printArray(arr, size);
    mergeSort(arr, size);
    printf("Sorted array (merge sort):\n");
    printArray(arr, size);
    return 0;
}