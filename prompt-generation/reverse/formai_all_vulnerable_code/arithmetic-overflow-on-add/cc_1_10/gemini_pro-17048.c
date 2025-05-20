//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 5

typedef struct bucket {
    int *data;
    int size;
} bucket_t;

bucket_t *create_bucket(int size) {
    bucket_t *bucket = malloc(sizeof(bucket_t));
    bucket->data = malloc(sizeof(int) * size);
    bucket->size = 0;
    return bucket;
}

void destroy_bucket(bucket_t *bucket) {
    free(bucket->data);
    free(bucket);
}

void insert_into_bucket(bucket_t *bucket, int value) {
    bucket->data[bucket->size++] = value;
}

void sort_bucket(bucket_t *bucket) {
    int i, j;
    for (i = 0; i < bucket->size - 1; i++) {
        for (j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->data[j] > bucket->data[j + 1]) {
                int temp = bucket->data[j];
                bucket->data[j] = bucket->data[j + 1];
                bucket->data[j + 1] = temp;
            }
        }
    }
}

void bucket_sort(int *data, int size) {
    int i, j;
    int max_value = data[0];
    int min_value = data[0];

    // Find the maximum and minimum values in the data
    for (i = 1; i < size; i++) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
        if (data[i] < min_value) {
            min_value = data[i];
        }
    }

    // Create a bucket for each range of values
    int num_buckets = (max_value - min_value) / BUCKET_SIZE + 1;
    bucket_t **buckets = malloc(sizeof(bucket_t *) * num_buckets);
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = create_bucket(BUCKET_SIZE);
    }

    // Insert the data into the buckets
    for (i = 0; i < size; i++) {
        int bucket_index = (data[i] - min_value) / BUCKET_SIZE;
        insert_into_bucket(buckets[bucket_index], data[i]);
    }

    // Sort each bucket
    for (i = 0; i < num_buckets; i++) {
        sort_bucket(buckets[i]);
    }

    // Concatenate the sorted buckets into the output array
    int output_index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < buckets[i]->size; j++) {
            data[output_index++] = buckets[i]->data[j];
        }
    }

    // Free the buckets
    for (i = 0; i < num_buckets; i++) {
        destroy_bucket(buckets[i]);
    }
    free(buckets);
}

int main() {
    int data[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int size = sizeof(data) / sizeof(data[0]);

    bucket_sort(data, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");

    return 0;
}