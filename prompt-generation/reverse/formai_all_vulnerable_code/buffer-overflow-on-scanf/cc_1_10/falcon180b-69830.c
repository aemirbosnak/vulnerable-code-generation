//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / n;
    int* bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = (int*) malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        int j = arr[i] / bucketSize;
        bucket[j] = (int*) realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            arr[k++] = bucket[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}