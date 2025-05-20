//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort Algorithm
void bubble_sort(int *array, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Quick Sort Algorithm
int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void measure_execution_time(void (*sort_func)(int *, size_t), int *array, size_t size) {
    clock_t start, end;
    start = clock();
    sort_func(array, size);
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by function: %.6f seconds\n", cpu_time_used);
}

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    size_t size;
    char choice;
    
    printf("Enter the size of the array: ");
    scanf("%zu", &size);
    
    int *array = (int *)malloc(size * sizeof(int));
    if (!array) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    
    generate_random_array(array, size);
    
    printf("Generated random array:\n");
    print_array(array, size);
    
    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Quick Sort\n");
    printf("Enter your choice (1/2): ");
    scanf(" %c", &choice);
    
    switch (choice) {
        case '1':
            printf("Starting Bubble Sort...\n");
            measure_execution_time((void (*)(int *, size_t)) bubble_sort, array, size);
            break;
        case '2':
            printf("Starting Quick Sort...\n");
            measure_execution_time((void (*)(int *, size_t)) quick_sort, array, size - 1);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    printf("Sorted array:\n");
    print_array(array, size);
    
    free(array);
    return 0;
}