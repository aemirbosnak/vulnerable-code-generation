//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_BUCKETS 100
#define MAX_NUM 100000

// Function to find the index of the bucket for a given element
int getBucketIndex(int arr[], int n, int element) {
    int bucketIndex = element / n;
    if (bucketIndex == MAX_BUCKETS) {
        bucketIndex = MAX_BUCKETS - 1;
    }
    return bucketIndex;
}

// Function to perform bucket sort on an array
void bucketSort(int arr[], int n) {
    int bucket[MAX_BUCKETS] = {0};
    int i, j;

    // Count the frequency of each element
    for (i = 0; i < n; i++) {
        bucket[getBucketIndex(arr, n, arr[i])]++;
    }

    // Modify the array to store the position of each element
    for (i = 0; i < n; i++) {
        arr[i] = getBucketIndex(arr, n, arr[i]);
    }

    // Sort the array by placing each element in its correct bucket
    for (i = 0; i < n; i++) {
        if (bucket[arr[i]] == 0) {
            bucket[arr[i]] = 1;
        } else {
            bucket[arr[i]]++;
        }
    }

    // Place the elements back in the array
    for (i = 0, j = 0; i < n; i++) {
        while (bucket[arr[i]] > 0) {
            arr[j++] = arr[i];
            bucket[arr[i]]--;
        }
    }
}

int main() {
    int arr[MAX_NUM];
    int n, i;

    // Read the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Read the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}