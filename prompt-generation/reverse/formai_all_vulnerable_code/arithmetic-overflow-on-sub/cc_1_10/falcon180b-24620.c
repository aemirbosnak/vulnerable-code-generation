//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANGE 1000
#define MAX_SIZE 1000

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size, int range) {
    int *buckets = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / range;
        buckets[bucket_index]++;
    }

    int *sorted_arr = (int *)malloc((size + range - 1) * sizeof(int));
    int sorted_size = 0;

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            sorted_arr[sorted_size++] = i * range + j;
        }
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / range;
        int bucket_offset = buckets[bucket_index] - 1;
        sorted_arr[sorted_size++] = arr[i];
        buckets[bucket_index]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }

    free(buckets);
    free(sorted_arr);
}

int main() {
    int size = rand_int(1, MAX_SIZE);
    int range = rand_int(1, MAX_RANGE);

    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(0, range * range);
    }

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size, range);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}