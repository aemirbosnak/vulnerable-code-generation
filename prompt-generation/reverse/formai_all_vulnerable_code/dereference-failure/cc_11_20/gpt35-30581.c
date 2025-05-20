//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 5

int main() {
    int input[] = {10, 1, 9, 3, 7, 2, 5, 4, 8, 6};
    int n = sizeof(input) / sizeof(int);
    int max_value = input[0];

    // Find maximum value in the input array
    for (int i = 1; i < n; i++) {
        if (input[i] > max_value) {
            max_value = input[i];
        }
    }

    // Calculate number of buckets needed
    int num_buckets = max_value / BUCKET_SIZE + 1;

    // Dynamically allocate memory for each bucket
    int** buckets = (int**) malloc(num_buckets * sizeof(int*));
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = (int*) malloc(BUCKET_SIZE * sizeof(int));
    }

    // Initialize each bucket to 0
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute input values into buckets
    for (int i = 0; i < n; i++) {
        int bucket_num = input[i] / BUCKET_SIZE;
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[bucket_num][j] == 0) {
                buckets[bucket_num][j] = input[i];
                break;
            }
        }
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 1; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] == 0) {
                break;
            }
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate sorted buckets into a single array
    int sorted[n];
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] == 0) {
                break;
            }
            sorted[index] = buckets[i][j];
            index++;
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // Free bucket memory
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);

    return 0;
}