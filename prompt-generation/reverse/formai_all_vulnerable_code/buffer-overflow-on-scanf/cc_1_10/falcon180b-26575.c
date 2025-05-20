//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of an element in an array
int findIndex(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int buckets[MAX_SIZE];
    int bucketCount[MAX_SIZE] = {0};
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum elements in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Initialize the buckets
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = -1;
    }

    // Place the elements in the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        buckets[bucketIndex] = i;
        bucketCount[bucketIndex]++;
    }

    // Sort the elements in each bucket
    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= -1) {
            int j = 0;
            while (j < bucketCount[i]) {
                int k = findIndex(arr, n, buckets[i] + j);
                swap(&arr[k], &arr[buckets[i] + j]);
                j++;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}