//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int *bucket_sort(int *array, int size) {
    int *result = malloc(size * sizeof(int));
    if (result == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    int *bucket = malloc(MAX_SIZE * sizeof(int));
    if (bucket == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    int max_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    int bucket_size = max_value / MAX_SIZE;

    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / bucket_size;
        bucket[bucket_index] = bucket[bucket_index] + 1;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        bucket[i] = bucket[i] + bucket[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int bucket_index = array[i] / bucket_size;
        result[bucket[bucket_index] - 1] = array[i];
        bucket[bucket_index] = bucket[bucket_index] - 1;
    }

    free(bucket);

    return result;
}

int main() {
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 1;
    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_SIZE;
    }

    int *sorted_array = bucket_sort(array, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    free(array);
    free(sorted_array);

    return 0;
}