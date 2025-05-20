//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_RANGE 1000

void generate_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int *bucket = (int *) malloc(MAX_RANGE * sizeof(int));

    for (int i = 0; i < MAX_RANGE; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        bucket[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < MAX_RANGE; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index++] = i;
        }
    }

    free(bucket);
}

int main() {
    int size = MAX_SIZE;
    int *arr = (int *) malloc(size * sizeof(int));

    generate_array(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}