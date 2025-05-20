//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE], n, i, j, k, max, min;

    // Take input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Take elements from user
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find maximum and minimum values in array
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

    // Calculate range
    k = max - min + 1;

    // Create empty buckets
    int buckets[k];
    for (i = 0; i < k; i++) {
        buckets[i] = 0;
    }

    // Place elements in buckets
    for (i = 0; i < n; i++) {
        j = arr[i] - min;
        buckets[j]++;
    }

    // Move elements back to array
    i = 0;
    for (j = 0; j < k; j++) {
        while (buckets[j] > 0) {
            arr[i++] = j + min;
            buckets[j]--;
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}