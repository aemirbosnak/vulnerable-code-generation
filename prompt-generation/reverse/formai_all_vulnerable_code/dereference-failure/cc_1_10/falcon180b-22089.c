//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

void generate_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void bucket_sort(int *arr, int size) {
    int *buckets = malloc(MAX_RANGE * sizeof(int));
    memset(buckets, 0, MAX_RANGE * sizeof(int));

    for (int i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }

    for (int i = 0; i < MAX_RANGE; i++) {
        if (buckets[i] > 0) {
            int j = 0;
            while (buckets[i] > 0) {
                arr[j++] = i;
                buckets[i]--;
            }
        }
    }

    free(buckets);
}

int main() {
    int size = MAX_SIZE;
    int *arr = malloc(size * sizeof(int));

    generate_array(arr, size);

    printf("Before Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, size);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}