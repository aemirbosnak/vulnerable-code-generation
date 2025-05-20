//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to swap two elements of an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int max) {
    int i, j, k;
    int* bucket[MAX_SIZE];
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int*)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n; i++) {
        k = arr[i] / max;
        if (k >= MAX_SIZE) {
            k = MAX_SIZE - 1;
        }
        bucket[k] = realloc(bucket[k], sizeof(int) * (n + 1));
        bucket[k][n] = arr[i];
    }
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < n; j++) {
            arr[j] = bucket[i][j];
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    partition(arr, n, max);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}