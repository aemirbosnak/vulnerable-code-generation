//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array of integers
int * generateRandomArray(int n) {
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

// Function to print the array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using Bucket Sort
void bucketSort(int *arr, int n) {
    int i, j;
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int *bucket = malloc(max * sizeof(int));
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
    for (i = 0, j = 0; i < max; i++) {
        for (int k = 0; k < bucket[i]; k++) {
            arr[j++] = i;
        }
    }
    free(bucket);
}

// Driver program to test above functions
int main() {
    int n = 100;
    int *arr = generateRandomArray(n);
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array is:\n");
    printArray(arr, n);
    return 0;
}