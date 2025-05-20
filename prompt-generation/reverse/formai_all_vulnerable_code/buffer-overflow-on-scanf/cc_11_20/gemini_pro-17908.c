//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 100
#define BUCKET_SIZE 10

int main() {
    int i, j, k, n, count;
    int *arr, *buckets[BUCKET_SIZE];

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create the buckets
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *)malloc(MAX_VAL * sizeof(int));
    }

    // Initialize the buckets
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < MAX_VAL; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++) {
        buckets[arr[i] / BUCKET_SIZE][arr[i] % BUCKET_SIZE]++;
    }

    // Sort the elements in each bucket
    for (i = 0; i < BUCKET_SIZE; i++) {
        count = 0;
        for (j = 0; j < MAX_VAL; j++) {
            for (k = 0; k < buckets[i][j]; k++) {
                arr[count++] = i * BUCKET_SIZE + j;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the buckets
    for (i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }

    // Free the memory allocated for the array
    free(arr);

    return 0;
}