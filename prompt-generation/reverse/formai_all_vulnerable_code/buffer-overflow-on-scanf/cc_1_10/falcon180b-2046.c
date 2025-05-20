//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000000

void generate_array(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *buckets = malloc(MAX_SIZE * sizeof(int));
    int bucket_size = MAX_SIZE;
    int max_value = INT_MIN;
    int min_value = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }

    int range = max_value - min_value + 1;
    int bucket_range = range / bucket_size;

    for (int i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min_value) / bucket_range;
        if (bucket_index >= MAX_SIZE) {
            bucket_index = MAX_SIZE - 1;
        }
        buckets[bucket_index]++;
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = min_value + i * bucket_range;
        }
    }

    free(buckets);
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}