//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = 0;
    }
}

void destroy_bucket(Bucket *b) {
    free(b->arr);
    b->size = 0;
}

void insert_element(Bucket *b, int element) {
    int index = element % b->size;
    b->arr[index]++;
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    Bucket *b = (Bucket *)malloc(sizeof(Bucket));
    init_bucket(b, size);

    for (int i = 0; i < size; i++) {
        insert_element(b, arr[i]);
    }

    int *sorted_arr = (int *)malloc(size * sizeof(int));
    int index = 0;

    for (int i = 0; i < b->size; i++) {
        for (int j = 0; j < b->arr[i]; j++) {
            sorted_arr[index++] = i * b->size + j;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }

    destroy_bucket(b);
    free(sorted_arr);
}

int main() {
    int arr[] = {5, 3, 8, 1, 9, 2, 6, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}