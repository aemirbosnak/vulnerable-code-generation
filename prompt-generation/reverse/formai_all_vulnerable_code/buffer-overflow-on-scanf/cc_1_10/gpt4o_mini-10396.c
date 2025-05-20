//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10 // Number of buckets
#define MAX_NUMBERS 100 // Maximum numbers to sort

typedef struct Bucket {
    float *values;
    int count;
} Bucket;

void initialize_buckets(Bucket *buckets) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].values = (float *)malloc(MAX_NUMBERS * sizeof(float));
        buckets[i].count = 0;
    }
}

void free_buckets(Bucket *buckets) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i].values);
    }
}

int get_bucket_index(float value) {
    return (int)(value * BUCKET_SIZE);
}

void insert_into_bucket(Bucket *buckets, float value) {
    int index = get_bucket_index(value);
    if (index >= BUCKET_SIZE) {
        index = BUCKET_SIZE - 1; // Handle edge case
    }
    buckets[index].values[buckets[index].count++] = value;
}

void sort_bucket(float *bucket, int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucket_sort(float *array, int n) {
    Bucket buckets[BUCKET_SIZE];
    initialize_buckets(buckets);

    for (int i = 0; i < n; i++) {
        insert_into_bucket(buckets, array[i]);
    }

    int k = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i].count > 0) {
            sort_bucket(buckets[i].values, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                array[k++] = buckets[i].values[j];
            }
        }
    }

    free_buckets(buckets);
}

// Helper function to print an array
void print_array(float *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    float numbers[MAX_NUMBERS];
    int n;

    printf("Enter number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    if (n > MAX_NUMBERS) {
        printf("Exceeds maximum allowed numbers.\n");
        return 1;
    }

    printf("Enter %d float numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &numbers[i]);
    }

    printf("Original Array:\n");
    print_array(numbers, n);

    bucket_sort(numbers, n);

    printf("Sorted Array:\n");
    print_array(numbers, n);

    return 0;
}