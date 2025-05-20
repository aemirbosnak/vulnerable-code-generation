//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int *buckets[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = malloc(sizeof(int) * size);
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_SIZE / size);
        int bucket_offset = arr[i] % (MAX_SIZE / size);
        int *bucket = buckets[bucket_index];
        bucket[bucket_offset] = arr[i];
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_SIZE / size);
        int bucket_offset = arr[i] % (MAX_SIZE / size);
        int *bucket = buckets[bucket_index];
        arr[i] = bucket[bucket_offset];
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);
    printf("Unsorted Array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted Array:\n");
    print_array(arr, size);

    return 0;
}