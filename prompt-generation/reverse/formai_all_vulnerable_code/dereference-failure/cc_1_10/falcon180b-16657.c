//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to compare two integers
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y)
        return -1;
    else if (x == y)
        return 0;
    else
        return 1;
}

// Function to perform bucket sort on an array of integers
void bucketSort(int arr[], int n) {
    int i, j, k;
    int max = arr[0];
    int min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int *bucket = malloc(range * sizeof(int));

    for (i = 0; i < n; i++) {
        k = arr[i] - min;
        bucket[k]++;
    }

    for (i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        k = arr[i] - min;
        arr[bucket[k] - 1] = arr[i];
        bucket[k]--;
    }

    free(bucket);
}

// Function to print an array of integers
void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Main function
int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}