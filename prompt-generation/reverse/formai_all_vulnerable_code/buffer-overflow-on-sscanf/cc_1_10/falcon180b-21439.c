//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int arr[], int size) {
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

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int size, max_size = MAX_SIZE;
    if (argc > 1) {
        sscanf(argv[1], "%d", &size);
        if (size > max_size) {
            printf("Error: Array size too large.\n");
            return 1;
        }
    } else {
        printf("Using default array size: %d\n", max_size);
    }

    int arr[max_size];
    generate_random_array(arr, max_size);

    printf("Original array:\n");
    print_array(arr, max_size);

    clock_t start_time = clock();
    bubble_sort(arr, max_size);
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    print_array(arr, max_size);

    printf("Time taken: %.3f seconds\n", elapsed_time);

    return 0;
}