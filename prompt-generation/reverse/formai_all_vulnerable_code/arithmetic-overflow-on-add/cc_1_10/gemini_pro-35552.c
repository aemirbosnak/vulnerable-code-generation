//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

typedef struct {
    int *data;
    int size;
    int capacity;
} bucket;

bucket *create_bucket(int capacity) {
    bucket *b = (bucket *)malloc(sizeof(bucket));
    b->data = (int *)malloc(sizeof(int) * capacity);
    b->size = 0;
    b->capacity = capacity;
    return b;
}

void destroy_bucket(bucket *b) {
    free(b->data);
    free(b);
}

void insert_bucket(bucket *b, int value) {
    if (b->size >= b->capacity) {
        b->data = (int *)realloc(b->data, sizeof(int) * (b->capacity *= 2));
    }
    b->data[b->size++] = value;
}

void sort_bucket(bucket *b) {
    int i, j;
    for (i = 0; i < b->size - 1; i++) {
        for (j = 0; j < b->size - i - 1; j++) {
            if (b->data[j] > b->data[j + 1]) {
                int tmp = b->data[j];
                b->data[j] = b->data[j + 1];
                b->data[j + 1] = tmp;
            }
        }
    }
}

bucket **create_buckets(int n) {
    bucket **buckets = (bucket **)malloc(sizeof(bucket *) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = create_bucket(BUCKET_SIZE);
    }
    return buckets;
}

void destroy_buckets(bucket **buckets, int n) {
    for (int i = 0; i < n; i++) {
        destroy_bucket(buckets[i]);
    }
    free(buckets);
}

void bucket_sort(int *a, int n) {
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    int bucket_count = (max - min) / BUCKET_SIZE + 1;
    bucket **buckets = create_buckets(bucket_count);

    for (int i = 0; i < n; i++) {
        insert_bucket(buckets[(a[i] - min) / BUCKET_SIZE], a[i]);
    }

    for (int i = 0; i < bucket_count; i++) {
        sort_bucket(buckets[i]);
    }

    int k = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            a[k++] = buckets[i]->data[j];
        }
    }

    destroy_buckets(buckets, bucket_count);
}

int main() {
    int a[] = {4, 2, 1, 5, 3};
    int n = sizeof(a) / sizeof(a[0]);

    bucket_sort(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}