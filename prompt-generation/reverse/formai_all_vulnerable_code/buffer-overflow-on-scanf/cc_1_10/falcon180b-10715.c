//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Determine the range of the array
    int range = max - min;

    // Determine the number of buckets
    int numBuckets = range / 10;

    // Create an array of empty buckets
    int buckets[numBuckets];

    // Initialize all buckets to empty
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = -1;
    }

    // Place each element in its corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / (range / numBuckets);
        if (buckets[bucketIndex] == -1) {
            buckets[bucketIndex] = i;
        } else {
            int j = buckets[bucketIndex];
            while (j!= -1) {
                j = (j + 1) % n;
            }
            buckets[bucketIndex] = j;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i]!= -1) {
            arr[index++] = arr[buckets[i]];
        }
    }
}

// Function to generate a random array of integers
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array of integers
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generateArray(arr, n);
    printf("Before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}