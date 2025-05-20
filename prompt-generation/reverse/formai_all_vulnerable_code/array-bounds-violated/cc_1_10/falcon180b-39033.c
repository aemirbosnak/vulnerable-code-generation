//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into n buckets
void partition(int arr[], int n, int max) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int i, j;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucket[max + 1];
    for (i = 0; i <= max; i++) {
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
    for (i = 0; i <= max; i++) {
        if (bucket[i] > 0) {
            for (j = 0; j < bucket[i]; j++) {
                arr[j] = i;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}