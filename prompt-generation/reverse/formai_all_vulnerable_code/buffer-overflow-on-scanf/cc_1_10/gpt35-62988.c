//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to sort elements using bucket sort algorithm
void bucketSort(float arr[], int n) {
    // Create an array of buckets
    int num_buckets = 10;
    float buckets[num_buckets][n];

    // Initialize all elements in each bucket to 0
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < n; j++) {
            buckets[i][j] = 0;
        }
    }

    // Fill the buckets with respective elements
    for (int i = 0; i < n; i++) {
        int bucket_index = num_buckets * arr[i];
        int j = 0;
        while (buckets[bucket_index][j] != 0) {
            j++;
        }
        buckets[bucket_index][j] = arr[i];
    }

    // Sort the elements in each bucket using insertion sort
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 1; j < n; j++) {
            float temp = buckets[i][j];
            if (temp != 0) {
                int k = j;
                while (k > 0 && buckets[i][k - 1] > temp) {
                    buckets[i][k] = buckets[i][k - 1];
                    k--;
                }
                buckets[i][k] = temp;
            }
        }
    }

    // Merge the sorted elements from each bucket into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Main function to test the bucketSort function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}