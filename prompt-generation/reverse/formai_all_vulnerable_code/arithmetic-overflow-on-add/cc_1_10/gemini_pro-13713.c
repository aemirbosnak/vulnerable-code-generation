//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

typedef struct bucket {
    int *arr;
    int size;
} bucket;

bucket *create_bucket(int size) {
    bucket *b = malloc(sizeof(bucket));
    b->arr = malloc(sizeof(int) * size);
    b->size = 0;
    return b;
}

void insert_into_bucket(bucket *b, int val) {
    b->arr[b->size++] = val;
}

void sort_bucket(bucket *b) {
    for (int i = 0; i < b->size - 1; i++) {
        for (int j = i + 1; j < b->size; j++) {
            if (b->arr[i] > b->arr[j]) {
                int temp = b->arr[i];
                b->arr[i] = b->arr[j];
                b->arr[j] = temp;
            }
        }
    }
}

void bucket_sort(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int num_buckets = max / BUCKET_SIZE + 1;
    bucket **buckets = malloc(sizeof(bucket *) * num_buckets);

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = create_bucket(BUCKET_SIZE);
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        insert_into_bucket(buckets[bucket_index], arr[i]);
    }

    for (int i = 0; i < num_buckets; i++) {
        sort_bucket(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
    }

    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {5, 3, 1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}