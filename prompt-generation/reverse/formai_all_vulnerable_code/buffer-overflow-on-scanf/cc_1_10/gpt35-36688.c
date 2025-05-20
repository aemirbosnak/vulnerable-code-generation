//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int left, int right) {
    int i = left, j = right, pivot = arr[(left + right)/2], temp;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

int main() {
    int arr[MAX_ARRAY_SIZE], temp[MAX_ARRAY_SIZE], size;
    printf("Enter the size of the array (max 1000000): ");
    scanf("%d", &size);
    if (size > MAX_ARRAY_SIZE) {
        printf("Array size too large!\n");
        return 0;
    }
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generate a random number between 0 and 999
    }
    // Benchmark bubble sort
    printf("Bubble Sort:\n");
    printf("Unsorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    double elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);
    // Benchmark quick sort
    printf("Quick Sort:\n");
    printf("Unsorted Array:\n");
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");
    start = clock();
    quick_sort(temp, 0, size - 1);
    end = clock();
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);
    return 0;
}