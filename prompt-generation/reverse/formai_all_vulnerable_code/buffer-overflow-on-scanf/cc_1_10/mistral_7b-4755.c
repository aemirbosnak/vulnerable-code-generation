//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10
#define BUCKET_COUNT 10

typedef struct {
    int *data;
    int capacity;
    int count;
} Bucket;

void read_input(int arr[], int size) {
    int num;
    for (int i = 0; i < size; ++i) {
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        arr[i] = num;
    }
}

void init_buckets(Bucket *buckets) {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        buckets[i].data = malloc(BUCKET_SIZE * sizeof(int));
        buckets[i].capacity = BUCKET_SIZE;
        buckets[i].count = 0;
    }
}

void write_buckets(Bucket *buckets) {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        if (buckets[i].count > 0) {
            for (int j = 0; j < buckets[i].count; ++j) {
                printf("%d ", buckets[i].data[j]);
            }
        }
        free(buckets[i].data);
    }
}

void bucket_sort(int arr[], int size, Bucket *buckets) {
    for (int i = 0; i < size; ++i) {
        int index = arr[i] / (BUCKET_SIZE / BUCKET_COUNT) * BUCKET_COUNT + arr[i] % (BUCKET_SIZE / BUCKET_COUNT);
        buckets[index].data[buckets[index].count++] = arr[i];
    }

    for (int i = 0; i < BUCKET_COUNT; ++i) {
        int start = 0;
        for (int j = 0; j < buckets[i].count; ++j) {
            arr[start++] = buckets[i].data[j];
        }
    }
}

int main() {
    int arr[100];
    int size;
    Bucket buckets[BUCKET_COUNT];

    clock_t start = clock();

    read_input(arr, sizeof(arr) / sizeof(arr[0]));
    size = sizeof(arr) / sizeof(arr[0]);

    init_buckets(buckets);
    bucket_sort(arr, size, buckets);

    printf("\nSize of the array: %d\n", size);
    printf("Time taken to sort: %fs\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    printf("\nSorted array: ");

    write_buckets(buckets);

    return 0;
}