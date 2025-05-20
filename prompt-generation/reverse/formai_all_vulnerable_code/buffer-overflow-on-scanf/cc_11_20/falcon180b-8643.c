//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, max, min;
    int buckets[MAX_SIZE];
    int count[MAX_SIZE] = {0};

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum and minimum values in the array
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

    // Create the buckets
    int bucketSize = (max - min) / n;
    for (i = 0; i < n; i++) {
        buckets[i] = min + i * bucketSize;
    }

    // Count the elements in each bucket
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        count[(arr[i] - min) / bucketSize]++;
    }

    // Place the elements in the correct buckets
    for (i = 0; i < n; i++) {
        buckets[(arr[i] - min) / bucketSize] += 1;
    }

    // Place the elements back into the array
    for (i = 0; i < n; i++) {
        arr[i] = buckets[(arr[i] - min) / bucketSize] - 1;
        buckets[(arr[i] - min) / bucketSize] -= 1;
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}