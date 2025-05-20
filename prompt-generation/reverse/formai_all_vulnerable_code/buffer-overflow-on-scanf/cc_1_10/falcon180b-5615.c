//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int *buckets[n];

    // create n empty buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSize * sizeof(int));
    }

    // place each element in its respective bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int index = 0;
        while (index < bucketSize && (index + 1) * bucketSize <= arr[i]) {
            index++;
        }
        buckets[bucketIndex][index] = arr[i];
    }

    // concatenate the sorted buckets back into the original array
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < bucketSize; k++) {
            if (buckets[i][k]!= -1) {
                arr[j++] = buckets[i][k];
            }
        }
    }
}

// function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements to be sorted: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}