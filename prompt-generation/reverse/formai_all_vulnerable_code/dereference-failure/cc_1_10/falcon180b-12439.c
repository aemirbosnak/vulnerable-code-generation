//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int *generate_random_array(int size) {
    int *array = (int *)malloc(sizeof(int) * size);
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_SIZE;
    }
    return array;
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bucket_sort(int *array, int size) {
    int *buckets = (int *)malloc(sizeof(int) * MAX_SIZE);
    int bucket_count = 0;
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / 10;
        if (bucket_index >= MAX_SIZE) {
            bucket_index = MAX_SIZE - 1;
        }
        buckets[bucket_index]++;
        bucket_count++;
    }
    int *sorted_array = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / 10;
        if (bucket_index >= MAX_SIZE) {
            bucket_index = MAX_SIZE - 1;
        }
        sorted_array[i] = buckets[bucket_index] + (i - buckets[bucket_index]);
        buckets[bucket_index]++;
    }
    free(buckets);
}

int main() {
    int size = 50;
    int *array = generate_random_array(size);
    printf("Unsorted array: ");
    print_array(array, size);
    bucket_sort(array, size);
    printf("Sorted array: ");
    print_array(array, size);
    free(array);
    return 0;
}