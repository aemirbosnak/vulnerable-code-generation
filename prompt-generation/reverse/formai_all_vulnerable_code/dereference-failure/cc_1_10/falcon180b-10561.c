//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 100

int *generate_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX;
    }
    return arr;
}

void bucket_sort(int *arr, int size) {
    int *buckets = (int *)malloc(RANGE * sizeof(int));
    int bucket_counts[RANGE] = {0};

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX / RANGE);
        bucket_counts[bucket_index]++;
    }

    for (int i = 1; i < RANGE; i++) {
        bucket_counts[i] += bucket_counts[i - 1];
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX / RANGE);
        buckets[bucket_counts[bucket_index] - 1] = arr[i];
        bucket_counts[bucket_index]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = buckets[i];
    }

    free(buckets);
}

int main() {
    srand(time(NULL));
    int size = MAX;

    int *arr = generate_array(size);
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);
    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}