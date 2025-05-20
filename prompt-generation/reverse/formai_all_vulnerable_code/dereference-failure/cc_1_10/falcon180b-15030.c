//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main() {
    int *arr = (int *) malloc(SIZE * sizeof(int));
    int i, j;
    clock_t start, end;

    // Fill the array with random numbers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using quicksort
    start = clock();
    for (i = 0; i < SIZE; i++) {
        int pivot = arr[i];
        int left = i;
        int right = SIZE - 1;
        while (left < right) {
            while (arr[left] > pivot) {
                left++;
            }
            while (arr[right] < pivot) {
                right--;
            }
            if (left < right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
    }
    end = clock();

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the execution time
    double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %lf seconds\n", elapsed_time);

    free(arr);
    return 0;
}