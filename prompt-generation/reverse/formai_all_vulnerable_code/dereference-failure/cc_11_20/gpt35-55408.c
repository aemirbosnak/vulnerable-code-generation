//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int main() {
    clock_t start_t, end_t;
    double total_t;

    int *arr = malloc(sizeof(int) * ARRAY_SIZE); // allocate dynamic memory

    // initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // BUBBLE SORT
    start_t = clock(); // start timer
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end_t = clock(); // end timer

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Bubble Sort took %f seconds to execute.\n", total_t);

    // SELECTION SORT
    start_t = clock(); // start timer
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    end_t = clock(); // end timer

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Selection Sort took %f seconds to execute.\n", total_t);

    // INSERTION SORT
    start_t = clock(); // start timer
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    end_t = clock(); // end timer

    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Insertion Sort took %f seconds to execute.\n", total_t);

    free(arr); // deallocate dynamic memory

    return 0;
}