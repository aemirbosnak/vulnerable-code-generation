//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VAL 1000

// Function to generate random numbers
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print an array
void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int *buckets = (int *)malloc(MAX_VAL * sizeof(int));
    for (int i = 0; i < MAX_VAL; i++) {
        buckets[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucket_idx = arr[i] / (MAX_VAL / size);
        buckets[arr[i] % (MAX_VAL / size)]++;
    }

    int idx = 0;
    for (int i = 0; i < MAX_VAL; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[idx++] = i * (MAX_VAL / size) + j;
        }
    }

    free(buckets);
}

// Function to generate an array of random numbers
int *gen_arr(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand_num(1, MAX_VAL);
    }
    return arr;
}

int main() {
    srand(time(NULL));

    int size = rand_num(1, MAX_SIZE);
    int *arr = gen_arr(size);

    printf("Unsorted array:\n");
    print_arr(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_arr(arr, size);

    free(arr);
    return 0;
}