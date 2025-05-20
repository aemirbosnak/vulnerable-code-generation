//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int size) {
    int i, j, k, n;
    int *bucket[MAX_SIZE];

    // Initialize all buckets to NULL
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Place each element into its corresponding bucket
    for (i = 0; i < size; i++) {
        n = arr[i] * MAX_SIZE / (MAX_SIZE - 1);
        if (bucket[n] == NULL) {
            bucket[n] = malloc(sizeof(int));
        }
        bucket[n][k++] = arr[i];
    }

    // Concatenate all the buckets to form the sorted array
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            for (k = 0; k < k; k++) {
                arr[i++] = bucket[j][k];
            }
            free(bucket[j]);
        }
    }
}

int main() {
    int i, n, max, min;
    int arr[MAX_SIZE];

    // Get the size of the array
    printf("Enter the size of the array (maximum 1000): ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the maximum and minimum values of the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Display the original array
    printf("Original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Sort the array using bucket sort
    srand(time(NULL));
    bucket_sort(arr, n);

    // Display the sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}