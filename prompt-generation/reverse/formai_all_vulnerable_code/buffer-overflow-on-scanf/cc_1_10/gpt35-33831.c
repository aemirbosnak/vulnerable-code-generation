//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Defining maximum value of array elements
#define MAX_VALUE 1000

// Defining bucket size
#define BUCKET_SIZE 10

// Function prototypes
void display(int arr[], int n);
void bucketSort(int arr[], int n);

int main() {
    int n, i;
    int arr[MAX_VALUE];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    display(arr, n);

    // Sorting the array using bucket sort
    bucketSort(arr, n);

    printf("Sorted array:\n");
    display(arr, n);

    return 0;
}

void display(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int i, j, k;
    int buckets[BUCKET_SIZE];

    // Initializing the bucket array with 0
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = 0;
    }

    // Counting the frequency of each element in the array
    for (i = 0; i < n; i++) {
        (buckets[arr[i] / BUCKET_SIZE])++;
    }

    // Sorting the elements in each bucket using insertion sort
    for (i = 0, k = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < buckets[i]; j++) {
            arr[k++] = (i * BUCKET_SIZE) + j;
        }
    }
}