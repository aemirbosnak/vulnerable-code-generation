//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, k;
    int arr[MAX_SIZE];
    int bucket[MAX_SIZE];
    int max, min;
    double start, end;

    srand(time(NULL));

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    // Find the maximum and minimum values
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

    // Determine the range of values
    int range = max - min;

    // Determine the number of buckets
    int num_buckets = range / 10;

    // Initialize the buckets
    for (i = 0; i < num_buckets; i++) {
        bucket[i] = 0;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        k = arr[i] / 10;
        bucket[k]++;
    }

    // Place the elements in the final array
    for (i = 0; i < n; i++) {
        k = arr[i] / 10;
        arr[i] = bucket[k] * 10 + arr[i] % 10;
        bucket[k]++;
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}