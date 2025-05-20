//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

void bucket_sort(double arr[], int n) {
    int i, j, k;
    double range, interval, *bucket[MAX_SIZE];

    // Initialize the bucket array
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (double *) malloc(n * sizeof(double));
    }

    // Find the range of the array
    range = arr[0] - arr[n - 1];

    // Calculate the interval for each bucket
    interval = range / MAX_SIZE;

    // Place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        k = (int) ((arr[i] - arr[0]) / interval);
        if (k >= MAX_SIZE) {
            k = MAX_SIZE - 1;
        }
        bucket[k] = (double *) realloc(bucket[k], (k + 1) * sizeof(double));
        bucket[k][k] = arr[i];
    }

    // Merge the sorted buckets back into the original array
    for (i = 0, j = 0; i < MAX_SIZE; i++) {
        while (j < n) {
            arr[j] = bucket[i][j];
            j++;
        }
    }

    // Free the bucket memory
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    double arr[MAX_SIZE];

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf ", arr[i]);
    }

    return 0;
}