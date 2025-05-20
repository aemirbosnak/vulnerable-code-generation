//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int main() {
    // Prepare the input: generate random numbers in the range [0, 1000)
    // (change the range as needed)
    unsigned int n = 1000000;
    unsigned int *input = (unsigned int *)malloc(n * sizeof(unsigned int));
    srand(0);
    for (unsigned int i = 0; i < n; i++) { input[i] = rand() % 1000; }

    // Create the output array
    unsigned int *output = (unsigned int *)malloc(n * sizeof(unsigned int));

    // Create the buckets
    unsigned int num_buckets = 10; // (change as needed)
    unsigned int **buckets = (unsigned int **)malloc(num_buckets * sizeof(unsigned int *));
    for (unsigned int i = 0; i < num_buckets; i++) { buckets[i] = (unsigned int *)malloc(n * sizeof(unsigned int)); }

    // Initialize the buckets by setting all their sizes to 0
    unsigned int *bucket_sizes = (unsigned int *)malloc(num_buckets * sizeof(unsigned int));
    for (unsigned int i = 0; i < num_buckets; i++) { bucket_sizes[i] = 0; }

    // Iterate over the input array
    for (unsigned int i = 0; i < n; i++) {
        unsigned int bucket_index = input[i] / (1000 / num_buckets);
        buckets[bucket_index][bucket_sizes[bucket_index]++] = input[i];
    }

    // Sort the buckets
    for (unsigned int i = 0; i < num_buckets; i++) {
        // Insertion sort
        for (unsigned int j = 1; j < bucket_sizes[i]; j++) {
            unsigned int key = buckets[i][j];
            unsigned int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate the buckets and store them in the output array
    unsigned int index = 0;
    for (unsigned int i = 0; i < num_buckets; i++) {
        for (unsigned int j = 0; j < bucket_sizes[i]; j++) { output[index++] = buckets[i][j]; }
    }

    // Print the sorted array
    for (unsigned int i = 0; i < n; i++) { printf("%u ", output[i]); }
    printf("\n");

    // Free the memory
    free(input);
    free(output);
    for (unsigned int i = 0; i < num_buckets; i++) { free(buckets[i]); }
    free(buckets);
    free(bucket_sizes);
    return 0;
}