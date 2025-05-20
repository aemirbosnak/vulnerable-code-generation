//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int i, n, max, min;
    int arr[MAX_SIZE];
    int buckets[MAX_SIZE];

    // Prompt user to enter array elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
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

    // Calculate the range of the array
    int range = max - min;

    // Determine the size of each bucket
    int bucketSize = range / n;

    // Initialize the buckets
    for (i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        buckets[bucketIndex]++;
    }

    // Sort the array by placing the elements in the correct order
    for (i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}