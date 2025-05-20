//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int temp;
    for (int j = low; j <= high-1; j++) {
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[high];
    array[high] = temp;
    return i+1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex-1);
        quickSort(array, partitionIndex+1, high);
    }
}

int main() {
    // Initialize an unsorted array
    int size = 10;
    int array[10] = { 5, 2, 9, 3, 6, 8, 1, 7, 4, 10 };
    printf("Unsorted array:\n");
    printArray(array, size);

    // Benchmark the quicksort algorithm
    printf("Benchmarking QuickSort Algorithm...\n");
    clock_t start_time = clock();
    quickSort(array, 0, size-1);
    clock_t end_time = clock();
    double elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    printArray(array, size);
    printf("Elapsed time: %.10f seconds\n", elapsed_time);
    
    return 0;
}