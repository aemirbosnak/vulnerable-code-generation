//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0];
    int *bucket[MAX_SIZE];

    // Find max and min elements in array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate bucket size
    int bucketSize = (max - min) / n;

    // Create empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = malloc(sizeof(int) * bucketSize);
    }

    // Place elements in buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j] = realloc(bucket[j], sizeof(int) * (++bucket[j][0]));
        bucket[j][bucket[j][0] - 1] = arr[i];
    }

    // Concatenate sorted buckets
    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[k++] = bucket[i][j];
        }
        free(bucket[i]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}