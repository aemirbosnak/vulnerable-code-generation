//Falcon-180B DATASET v1.0 Category: Sorting ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000

// Function prototypes
void init_data(int *data, int size);
void print_data(int *data, int size);
void merge_data(int *data1, int size1, int *data2, int size2, int *result, int *result_size);
void merge_sort(int *data, int size, int *result, int *result_size);

int main() {
    int *data, *result;
    int data_size, result_size;

    // Generate random data
    srand(time(NULL));
    data_size = rand() % MAX_DATA_SIZE + 1;
    data = (int *)malloc(data_size * sizeof(int));
    init_data(data, data_size);

    // Sort data
    merge_sort(data, data_size, result, &result_size);

    // Print sorted data
    printf("Sorted data:\n");
    print_data(result, result_size);

    // Free memory
    free(data);
    free(result);

    return 0;
}

void init_data(int *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }
}

void print_data(int *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void merge_data(int *data1, int size1, int *data2, int size2, int *result, int *result_size) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (data1[i] <= data2[j]) {
            result[k++] = data1[i++];
        } else {
            result[k++] = data2[j++];
        }
    }

    while (i < size1) {
        result[k++] = data1[i++];
    }

    while (j < size2) {
        result[k++] = data2[j++];
    }

    *result_size = k;
}

void merge_sort(int *data, int size, int *result, int *result_size) {
    if (size <= 1) {
        *result_size = size;
        result = data;
        return;
    }

    int mid = size / 2;
    int *left_data, *right_data;
    int left_size, right_size;

    left_data = (int *)malloc(mid * sizeof(int));
    right_data = (int *)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left_data[i] = data[i];
    }

    for (int i = mid; i < size; i++) {
        right_data[i - mid] = data[i];
    }

    merge_sort(left_data, mid, result, result_size);
    merge_sort(right_data, size - mid, result, result_size);

    merge_data(left_data, mid, right_data, size - mid, result, result_size);

    free(left_data);
    free(right_data);
}