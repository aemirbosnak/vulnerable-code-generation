//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int compare(const void *a, const void *b) {
    int *key_a = (int*)a;
    int *key_b = (int*)b;
    return *key_a - *key_b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int range = MAX_RANGE;
    int *buckets = (int*)malloc(MAX_SIZE * sizeof(int));
    memset(buckets, 0, MAX_SIZE * sizeof(int));

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / range;
        buckets[bucket_index]++;
    }

    int *output = (int*)malloc(size * sizeof(int));
    int output_index = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < buckets[i]; j++) {
                output[output_index++] = i * range;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / range;
        int position = buckets[bucket_index] - 1;
        output[output_index++] = arr[i];
        buckets[bucket_index]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(output);
    free(buckets);
}

int main() {
    int size = MAX_SIZE;
    int *arr = (int*)malloc(size * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }

    print_array(arr, size);

    bucket_sort(arr, size);

    print_array(arr, size);

    free(arr);

    return 0;
}