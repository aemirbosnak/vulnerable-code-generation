//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_VALUE 100

typedef struct {
    int *arr;
    int size;
} Bucket;

void create_bucket(Bucket *b, int size) {
    b->arr = malloc(size * sizeof(int));
    b->size = size;
}

void delete_bucket(Bucket *b) {
    free(b->arr);
}

void insert_into_bucket(Bucket *b, int value) {
    int index = rand() % b->size;
    b->arr[index] = value;
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
}

void bucket_sort(int *arr, int size) {
    int max_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    Bucket *buckets = malloc(max_value + 1 * sizeof(Bucket));
    for (int i = 0; i <= max_value; i++) {
        create_bucket(&buckets[i], 0);
    }

    for (int i = 0; i < size; i++) {
        insert_into_bucket(&buckets[arr[i] % max_value], arr[i]);
    }

    int index = 0;
    for (int i = 0; i <= max_value; i++) {
        while (buckets[i].size > 0) {
            arr[index++] = buckets[i].arr[--(buckets[i].size)];
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    srand(time(NULL));

    int arr[] = { 5, 2, 8, 3, 6, 1, 7, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);

    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}