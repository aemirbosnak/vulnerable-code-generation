//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000000

void generate_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int *buckets = (int *)malloc(MAX_SIZE * sizeof(int));
    int num_buckets = (MAX_VALUE / size) + 1;

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / size;
        buckets[bucket_index]++;
    }

    int *sorted_arr = (int *)malloc(size * sizeof(int));
    int sorted_arr_index = 0;

    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            sorted_arr[sorted_arr_index++] = i * size;
        }
    }

    int k = 0;
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / size;
        while (k < sorted_arr[sorted_arr_index - 1]) {
            sorted_arr[sorted_arr_index++] = sorted_arr[sorted_arr_index - 1];
        }
        sorted_arr[sorted_arr_index++] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }

    free(buckets);
    free(sorted_arr);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    generate_array(arr, size);

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}