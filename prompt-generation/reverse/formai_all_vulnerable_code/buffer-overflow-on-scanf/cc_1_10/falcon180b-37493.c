//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

void create_array(int arr[], int size, int range) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size, int range) {
    int *buckets = (int *) malloc(range * sizeof(int));
    int bucket_size = range / size;

    for (int i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        buckets[arr[i] / bucket_size]++;
    }

    int *sorted_arr = (int *) malloc(size * sizeof(int));
    sorted_arr[0] = 0;

    for (int i = 1; i < range; i++) {
        sorted_arr[i] = sorted_arr[i - 1] + buckets[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int bucket_index = arr[i] / bucket_size;
        sorted_arr[arr[i] / bucket_size]--;
        arr[sorted_arr[arr[i] / bucket_size] + bucket_index] = arr[i];
    }

    free(buckets);
    free(sorted_arr);
}

int main() {
    int size, range;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the range of the array: ");
    scanf("%d", &range);

    int arr[size];
    create_array(arr, size, range);

    printf("Unsorted array:\n");
    print_array(arr, size);

    clock_t start_time = clock();
    bucket_sort(arr, size, range);
    clock_t end_time = clock();

    printf("Sorted array:\n");
    print_array(arr, size);

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to sort the array: %.6f seconds\n", time_taken);

    return 0;
}