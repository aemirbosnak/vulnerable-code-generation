//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    // Find the maximum element in the array 
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create an array of buckets
    int* buckets = (int*)malloc(sizeof(int) * (max + 1));
    if (buckets == NULL) {
        printf("Error: Could not allocate memory");
        return;
    }

    // Initialize all the elements of the buckets array to 0
    for (int i = 0; i <= max; i++) {
        buckets[i] = 0;
    }

    // Store the number of occurrences of each element in the array
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Sort the array using the buckets array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index] = i;
            index++;
        }
    }

    // Free the allocated memory
    free(buckets);

    // Display the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Invalid input");
        return 0;
    }

    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL) {
        printf("Error: Could not allocate memory");
        return 0;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    // Free the allocated memory
    free(arr);

    return 0;
}