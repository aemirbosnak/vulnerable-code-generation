//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = -1;
    }
}

void free_bucket(Bucket *b) {
    free(b->arr);
}

void insert_bucket(Bucket *b, int val) {
    int index = val % b->size;
    if (b->arr[index] == -1) {
        b->arr[index] = val;
    }
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        if (b->arr[i]!= -1) {
            printf("%d ", b->arr[i]);
        }
    }
}

void bucket_sort(int *arr, int size) {
    Bucket *b = (Bucket *)malloc(sizeof(Bucket));
    init_bucket(b, size);

    for (int i = 0; i < size; i++) {
        insert_bucket(b, arr[i]);
    }

    int *sorted_arr = (int *)malloc(size * sizeof(int));
    int index = 0;

    for (int i = 0; i < b->size; i++) {
        if (b->arr[i]!= -1) {
            sorted_arr[index] = b->arr[i];
            index++;
        }
    }

    free_bucket(b);

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }

    free(sorted_arr);
}

void generate_random_array(int *arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    int size = MAX_SIZE;
    int *arr = (int *)malloc(size * sizeof(int));

    generate_random_array(arr, size);

    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}