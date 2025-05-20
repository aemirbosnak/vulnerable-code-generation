//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 100

void bucket_sort(int input_arr[MAX_SIZE], int output_arr[MAX_SIZE], int bucket_size, int num_buckets) {
    int i, j, index, min_index;
    int *buckets[num_buckets];

    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *)calloc(bucket_size, sizeof(int));
    }

    for (i = 0; i < MAX_SIZE; i++) {
        index = input_arr[i] / bucket_size;
        buckets[index][input_arr[i] % bucket_size]++;
    }

    i = 0;
    for (j = 0; j < num_buckets; j++) {
        for (index = 0; index < bucket_size; index++) {
            while (buckets[j][index]--) {
                output_arr[i++] = index;
            }
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        input_arr[i] = output_arr[i];
    }

    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
}

int main() {
    int input_arr[MAX_SIZE], output_arr[MAX_SIZE];
    int i, bucket_size = 5, num_buckets;

    num_buckets = (MAX_SIZE - 1) / bucket_size + 1;

    printf("Enter %d numbers:\n", MAX_SIZE);
    for (i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &input_arr[i]);
    }

    bucket_sort(input_arr, output_arr, bucket_size, num_buckets);

    printf("\nSorted array: \n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", output_arr[i]);
    }
    printf("\n");

    return 0;
}