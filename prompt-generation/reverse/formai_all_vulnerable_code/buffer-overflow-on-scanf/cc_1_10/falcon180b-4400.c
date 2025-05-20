//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int n, int pivot) {
    int i = -1, j = 0;
    for (int k = 0; k < n; k++) {
        if (arr[k] <= pivot) {
            swap(&arr[k], &arr[++i]);
        }
    }
    swap(&arr[i + 1], &arr[n - 1]);
    return i + 1;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int* bucket = (int*)malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / range;
        bucket[index]++;
    }
    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i * range + min;
            bucket[i]--;
        }
    }
    free(bucket);
}

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
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}