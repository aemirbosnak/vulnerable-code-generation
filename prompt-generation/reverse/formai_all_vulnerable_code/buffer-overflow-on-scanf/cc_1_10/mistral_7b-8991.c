//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 10
#define BLOCK_SIZE 5

typedef struct Bucket {
    int count;
    int *data;
} Bucket;

void bucket_sort(int arr[], int size) {
    Bucket *bucket_arr = (Bucket *) calloc(BLOCK_SIZE, sizeof(Bucket));
    int i, index;

    for (i = 0; i < BLOCK_SIZE; i++) {
        bucket_arr[i].count = 0;
        bucket_arr[i].data = (int *) calloc(SIZE, sizeof(int));
    }

    for (i = 0; i < size; i++) {
        index = (arr[i] / (SIZE / BLOCK_SIZE)) % BLOCK_SIZE;
        bucket_arr[index].data[bucket_arr[index].count++] = arr[i];
    }

    for (i = 0; i < BLOCK_SIZE; i++) {
        int j, k, temp;

        if (bucket_arr[i].count > 0) {
            for (j = 0; j < bucket_arr[i].count - 1; j++) {
                for (k = j + 1; k < bucket_arr[i].count; k++) {
                    if (bucket_arr[i].data[j] > bucket_arr[i].data[k]) {
                        temp = bucket_arr[i].data[j];
                        bucket_arr[i].data[j] = bucket_arr[i].data[k];
                        bucket_arr[i].data[k] = temp;
                    }
                }
            }
        }

        for (j = 0; j < bucket_arr[i].count; j++) {
            arr[i * (SIZE / BLOCK_SIZE) + j] = bucket_arr[i].data[j];
        }
    }

    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    free(bucket_arr);
}

int main() {
    int arr[SIZE];
    int i;

    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, SIZE);

    return 0;
}