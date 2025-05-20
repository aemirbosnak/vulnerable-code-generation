//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define BUCKET_SIZE 10

typedef struct {
    int *arr;
    int size;
    int capacity;
} Bucket;

void init_bucket(Bucket *b, int capacity) {
    b->arr = (int *)malloc(capacity * sizeof(int));
    b->size = 0;
    b->capacity = capacity;
}

void free_bucket(Bucket *b) {
    free(b->arr);
}

void insert_bucket(Bucket *b, int value) {
    if (b->size == b->capacity) {
        b->capacity *= 2;
        b->arr = (int *)realloc(b->arr, b->capacity * sizeof(int));
    }
    b->arr[b->size++] = value;
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    Bucket *buckets = (Bucket *)malloc(MAX_SIZE * sizeof(Bucket));
    int max_value = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    int bucket_size = max_value / BUCKET_SIZE + 1;
    for (int i = 0; i < MAX_SIZE; i++) {
        init_bucket(&buckets[i], bucket_size);
    }
    for (int i = 0; i < size; i++) {
        int index = arr[i] / BUCKET_SIZE;
        insert_bucket(&buckets[index], arr[i]);
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        insert_bucket(arr, buckets[i].arr[0]);
        for (int j = 1; j < buckets[i].size; j++) {
            insert_bucket(arr, buckets[i].arr[j]);
        }
        free_bucket(&buckets[i]);
    }
    free(buckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
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
    free(arr);
    return 0;
}