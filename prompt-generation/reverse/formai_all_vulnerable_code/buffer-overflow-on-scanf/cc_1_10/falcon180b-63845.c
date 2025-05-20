//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int *arr, int size) {
    int *buckets = malloc(MAX_SIZE * sizeof(int));
    int bucket_size = (int) (size / MAX_SIZE);

    for (int i = 0; i < size; i++) {
        int index = arr[i] / bucket_size;
        if (index >= MAX_SIZE) {
            index = MAX_SIZE - 1;
        }
        buckets[index] = buckets[index] + 1;
    }

    int *sorted_arr = malloc(size * sizeof(int));
    int sorted_index = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < buckets[i]; j++) {
                sorted_arr[sorted_index++] = i * bucket_size + j;
            }
        }
    }

    free(buckets);

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }

    free(sorted_arr);
}

int main() {
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    printf("Enter elements of array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        swap(&arr[i], &arr[rand() % size]);
    }

    printf("Unsorted array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);

    return 0;
}