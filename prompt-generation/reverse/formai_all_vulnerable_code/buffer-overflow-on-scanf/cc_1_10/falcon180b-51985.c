//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, bucketSize;

    // Find the range of the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the bucket size
    range = max - min + 1;
    bucketSize = range / n;

    // Create n buckets
    int *bucket[n];
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(bucketSize * sizeof(int));
    }

    // Put elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        bucket[j] = realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }

    // Merge the buckets
    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucketSize; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, i;

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}