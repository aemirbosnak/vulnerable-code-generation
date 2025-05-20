//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

void fill_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void sort_array(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size = SIZE;
    int *array1 = (int *)malloc(size * sizeof(int));
    int *array2 = (int *)malloc(size * sizeof(int));

    fill_array(array1, size);
    fill_array(array2, size);

    clock_t start_time = clock();
    sort_array(array1, size);
    clock_t end_time = clock();
    double time_taken1 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    sort_array(array2, size);
    end_time = clock();
    double time_taken2 = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken for first array: %f seconds\n", time_taken1);
    printf("Time taken for second array: %f seconds\n", time_taken2);

    free(array1);
    free(array2);

    return 0;
}