//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALG_COUNT 3
typedef void (*benchmark_func)(int*, int);

// Algorithms to benchmark
void algo1(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *= 2;
    }
}

void algo2(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] += i;
    }
}

void algo3(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

// Benchmark function
void benchmark(benchmark_func algo, int* arr, int n, const char* name) {
    clock_t start = clock();
    algo(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s: %d elements processed in %.12fs\n", name, n, time_taken);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*)calloc(size, sizeof(int));
    if (arr == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    printf("\nAvailable algorithms:\n");
    for (int i = 0; i < ALG_COUNT; i++) {
        printf("%d. Algorithm %d\n", i + 1, i + 1);
    }

    int choice;
    printf("\nEnter the algorithm number to benchmark: ");
    scanf("%d", &choice);

    benchmark((benchmark_func)(&algo1), arr, size, "Algo 1: Double each element");
    benchmark((benchmark_func)(&algo2), arr, size, "Algo 2: Increment each element by its index");
    benchmark((benchmark_func)(&algo3), arr, size, "Algo 3: Bubble sort the array");

    free(arr);
    return 0;
}