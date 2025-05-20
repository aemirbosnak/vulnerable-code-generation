//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compare two integers
int compare(const void *a, const void *b) {
    if (*(int *)a < *(int *)b)
        return -1;
    else if (*(int *)a > *(int *)b)
        return 1;
    else
        return 0;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, bucket[MAX_SIZE];

    // Find the range of the array elements
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the range and bucket size
    range = max - min + 1;
    for (i = 0; i < range; i++)
        bucket[i] = 0;

    // Place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        bucket[j]++;
    }

    // Place the elements back in the array
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        arr[i] = min + j * range;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n, i;
    int arr[MAX_SIZE];

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}