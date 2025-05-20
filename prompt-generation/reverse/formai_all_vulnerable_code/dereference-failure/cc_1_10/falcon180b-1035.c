//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_SIZE 100000

typedef struct {
    int *array;
    int size;
} Bucket;

void create_bucket(Bucket *bucket, int size) {
    bucket->array = (int *)malloc(size * sizeof(int));
    bucket->size = size;
}

void destroy_bucket(Bucket *bucket) {
    free(bucket->array);
}

void insert_value(Bucket *bucket, int value) {
    int index = rand() % bucket->size;
    bucket->array[index] = value;
}

void print_bucket(Bucket bucket) {
    for (int i = 0; i < bucket.size; i++) {
        printf("%d ", bucket.array[i]);
    }
    printf("\n");
}

void bucket_sort(Bucket *buckets, int num_buckets, int *sorted_array, int size) {
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            sorted_array[j] = buckets[i].array[j];
        }
    }
}

int main() {
    srand(time(NULL));

    int size = 100000;
    int num_buckets = 10;

    int *sorted_array = (int *)malloc(size * sizeof(int));

    printf("Creating %d buckets...\n", num_buckets);
    Bucket *buckets = (Bucket *)malloc(num_buckets * sizeof(Bucket));

    for (int i = 0; i < num_buckets; i++) {
        create_bucket(&buckets[i], MAX_SIZE);
    }

    printf("Inserting %d values into buckets...\n", size);
    for (int i = 0; i < size; i++) {
        int value = rand() % 100000;
        int bucket_index = rand() % num_buckets;
        insert_value(&buckets[bucket_index], value);
    }

    printf("Printing buckets before sorting...\n");
    for (int i = 0; i < num_buckets; i++) {
        print_bucket(buckets[i]);
    }

    bucket_sort(buckets, num_buckets, sorted_array, size);

    printf("Printing sorted array...\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    for (int i = 0; i < num_buckets; i++) {
        destroy_bucket(&buckets[i]);
    }
    free(buckets);
    free(sorted_array);

    return 0;
}