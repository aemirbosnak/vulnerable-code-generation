//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int i, n, max_val, min_val;
    int arr[MAX_SIZE];
    int bucket[MAX_SIZE];

    // Prompt user to input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Prompt user to input array elements
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

    // Calculate the range of the array
    int range = max_val - min_val + 1;

    // Calculate the size of each bucket
    int bucket_size = range / n;

    // Initialize the buckets
    for (i = 0; i < n; i++) {
        bucket[i] = -1;
    }

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val) / bucket_size;
        if (bucket[bucket_index] == -1) {
            bucket[bucket_index] = i;
        } else {
            int j = bucket[bucket_index];
            while (j < i) {
                j++;
            }
            bucket[j] = i;
        }
    }

    // Sort the array using the bucket indices
    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val) / bucket_size;
        int j = bucket[bucket_index];
        while (j < i) {
            j++;
        }
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        bucket[bucket_index] = j;
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}