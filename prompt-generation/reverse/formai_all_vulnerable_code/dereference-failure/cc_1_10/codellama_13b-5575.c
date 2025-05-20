//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genius
/*
 * C Bucket Sort Implementation
 *
 * Author: [Your Name]
 * Date: [Date]
 *
 * Time complexity: O(n + k)
 * Space complexity: O(n + k)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100

void bucketSort(int arr[], int n) {
    int i, j;
    int min = arr[0];
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    int range = max - min + 1;
    int size = n / range;
    int* buckets[range];
    for (i = 0; i < range; i++) {
        buckets[i] = (int*)malloc(size * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / size;
        buckets[index][i % size] = arr[i];
    }
    i = 0;
    for (j = 0; j < range; j++) {
        for (i = 0; i < size; i++) {
            arr[i] = buckets[j][i];
        }
    }
    for (i = 0; i < range; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[] = {3, 0, 2, 5, 2, 3, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}