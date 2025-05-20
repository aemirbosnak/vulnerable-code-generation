//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int n, i, j, k, max_val, min_val, bin_size;
    float range;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum and minimum values in the array
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // Calculate the range and number of buckets
    range = max_val - min_val;
    if (range == 0) {
        printf("Error: Array contains only one value.\n");
        exit(1);
    }
    bin_size = range / MAX_SIZE;
    if (bin_size == 0) {
        bin_size = 1;
    }

    // Create empty buckets
    int *buckets[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++) {
        k = (arr[i] - min_val) / bin_size;
        if (k >= MAX_SIZE) {
            k = MAX_SIZE - 1;
        }
        buckets[k][k * n / MAX_SIZE] = arr[i];
    }

    // Sort the buckets and merge them
    for (i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= NULL) {
            for (j = 0; j < n; j++) {
                arr[j] = buckets[i][j];
            }
            free(buckets[i]);
            break;
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}