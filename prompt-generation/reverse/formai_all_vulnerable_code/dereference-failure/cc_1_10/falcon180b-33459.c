//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = -1;
    }
}

void free_bucket(Bucket *b) {
    free(b->arr);
}

void insert_into_bucket(Bucket *b, int val) {
    int idx = val % b->size;
    if (b->arr[idx] == -1) {
        b->arr[idx] = val;
    }
}

void print_bucket(Bucket b) {
    for (int i = 0; i < b.size; i++) {
        if (b.arr[i]!= -1) {
            printf("%d ", b.arr[i]);
        }
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    Bucket *buckets = malloc(MAX_SIZE * sizeof(Bucket));
    for (int i = 0; i < MAX_SIZE; i++) {
        init_bucket(&buckets[i], size);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int bucket_idx = rand() % MAX_SIZE;
        insert_into_bucket(&buckets[bucket_idx], arr[i]);
    }

    int sorted_idx = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i].arr[0]!= -1) {
            for (int j = 0; j < buckets[i].size; j++) {
                arr[sorted_idx++] = buckets[i].arr[j];
            }
        }
    }

    free(buckets);
}

int main() {
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}