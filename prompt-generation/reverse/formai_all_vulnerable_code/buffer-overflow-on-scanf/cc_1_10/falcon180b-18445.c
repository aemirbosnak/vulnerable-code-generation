//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int* arr, int size) {
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

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");
    print_array(arr, size);

    clock_t start = clock();
    bubble_sort(arr, size);
    clock_t end = clock();

    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    print_array(arr, size);

    printf("Time taken for sorting: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}