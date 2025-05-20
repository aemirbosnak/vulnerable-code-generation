//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void generateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size\n");
        return 1;
    }

    generateArray(arr, size);
    printf("Unsorted array:\n");
    printArray(arr, size);

    clock_t start = clock();
    bubbleSort(arr, size);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, size);

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %.4f seconds\n", time_taken);

    return 0;
}