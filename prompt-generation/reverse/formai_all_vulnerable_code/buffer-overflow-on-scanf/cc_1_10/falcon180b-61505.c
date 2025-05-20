//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two elements
int compare(const void* a, const void* b) {
    int* ia = (int*)a;
    int* ib = (int*)b;
    return (*ia - *ib);
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j;
    int* bucket[MAX_SIZE];

    // Create n empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int*)malloc(sizeof(int));
    }

    // Put each element in its respective bucket
    for (i = 0; i < n; i++) {
        int index = arr[i] * n / (MAX_SIZE - 1);
        if (index == n - 1) {
            index--;
        }
        bucket[index] = (int*)realloc(bucket[index], sizeof(int) * (i + 2));
        bucket[index][i] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < n; i++) {
        qsort(bucket[i], n, sizeof(int), compare);
    }

    // Concatenate all the sorted buckets
    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[k++] = *(bucket[i] + j);
        }
    }

    // Free the memory allocated for the buckets
    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int* arr = (int*)malloc(sizeof(int) * n);

    // Fill the array with random numbers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}