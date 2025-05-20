//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 10000

void generate_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucket_sort(int *arr, int size) {
    int *bucket = malloc(MAX_VALUE * sizeof(int));
    int num_buckets = MAX_VALUE;
    int bucket_size = size / num_buckets;

    for (int i = 0; i < num_buckets; i++) {
        int count = 0;
        for (int j = i * bucket_size; j < (i + 1) * bucket_size && j < size; j++) {
            bucket[arr[j]]++;
        }
        for (int k = 0; k < MAX_VALUE; k++) {
            while (bucket[k] > 0) {
                arr[i * bucket_size + count++] = k;
                bucket[k]--;
            }
        }
    }

    free(bucket);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    generate_array(arr, size);
    printf("Unsorted Array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted Array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}