//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

// Function to compare two integers
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    else if (x == y)
        return 0;
    else
        return 1;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int bucket[MAX_SIZE];
    int i, j, k;

    // Initialize all buckets to empty
    for (i = 0; i < MAX_SIZE; i++)
        bucket[i] = -1;

    // Insert each element into its appropriate bucket
    for (i = 0; i < n; i++) {
        bucket[arr[i] / 10]++;
    }

    // Move elements back into the array in sorted order
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= -1) {
            for (k = 0; k < bucket[j]; k++) {
                arr[i++] = j * 10 + k;
            }
        }
    }
}

// Main function
int main() {
    int arr[MAX_SIZE], n;

    // Prompt user for input
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Prompt user for elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}