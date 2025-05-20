//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j, k, index;
    int *bucket[MAX_SIZE];

    // Create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int*)malloc(n * sizeof(int));
    }

    // Put elements in the correct bucket
    for (i = 0; i < n; i++) {
        index = arr[i] * MAX_SIZE / (n - 1);
        if (index == MAX_SIZE - 1) {
            index = MAX_SIZE - 2;
        }
        bucket[index] = (int*)realloc(bucket[index], (index + 1) * sizeof(int));
        bucket[index][index] = arr[i];
    }

    // Sort each bucket
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            for (k = j + 1; k < bucket[i][0]; k++) {
                if (bucket[i][j] > bucket[i][k]) {
                    swap(&bucket[i][j], &bucket[i][k]);
                }
            }
        }
    }

    // Combine sorted buckets
    j = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (k = 0; k < bucket[i][0]; k++) {
            arr[j] = bucket[i][k];
            j++;
        }
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

// Function to generate random array
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    generateArray(arr, n);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}