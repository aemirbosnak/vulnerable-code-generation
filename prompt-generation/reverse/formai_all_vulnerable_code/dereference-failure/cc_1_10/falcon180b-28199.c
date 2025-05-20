//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

typedef struct {
    int *arr;
    int size;
} Bucket;

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(Bucket *buckets, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        qsort(buckets[i].arr, buckets[i].size, sizeof(int), compare_int);
    }
}

int main() {
    srand(time(NULL));

    int num_buckets = 10;
    Bucket *buckets = (Bucket *)malloc(sizeof(Bucket) * num_buckets);

    for (int i = 0; i < num_buckets; i++) {
        buckets[i].arr = (int *)malloc(sizeof(int) * MAX_SIZE);
        buckets[i].size = 0;
    }

    int num_elements = MAX_SIZE;
    for (int i = 0; i < num_elements; i++) {
        int bucket_idx = rand_int(0, num_buckets - 1);
        int value = rand_int(0, MAX_RANGE);
        int *arr = buckets[bucket_idx].arr;
        int size = buckets[bucket_idx].size;

        if (size >= MAX_SIZE) {
            printf("Bucket %d is full!\n", bucket_idx);
            continue;
        }

        arr[size] = value;
        buckets[bucket_idx].size++;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < num_buckets; i++) {
        print_array(buckets[i].arr, buckets[i].size);
    }

    bucket_sort(buckets, num_buckets);

    printf("After sorting:\n");
    for (int i = 0; i < num_buckets; i++) {
        print_array(buckets[i].arr, buckets[i].size);
    }

    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i].arr);
    }
    free(buckets);

    return 0;
}