//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 10000

int main() {
    int n;
    int i, j;
    int *arr;
    int *bucket;
    int max_value = 0;

    // Prompt user for array size
    printf("Enter array size: ");
    scanf("%d", &n);

    // Allocate memory for array
    arr = (int *)malloc(n * sizeof(int));

    // Prompt user for array elements
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Update max value
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Allocate memory for bucket
    bucket = (int *)malloc(max_value * sizeof(int));

    // Initialize bucket with zeros
    for (i = 0; i < max_value; i++) {
        bucket[i] = 0;
    }

    // Insert elements into bucket
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Modify bucket to contain actual positions
    for (i = 1; i < max_value; i++) {
        bucket[i] += bucket[i - 1];
    }

    // Sort array
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < max_value; j++) {
            if (arr[i] == j) {
                arr[bucket[j] - 1] = arr[i];
                bucket[j]--;
                break;
            }
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}