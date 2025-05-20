//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to compare two elements
int compare(int a, int b) {
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Create an array of buckets
    int* bucket = (int*) malloc(range * sizeof(int));
    if (bucket == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    // Initialize all buckets to 0
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    // Place each element in its corresponding bucket
    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    // Modify the array to contain the sorted elements
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index++] = i + min;
        }
    }

    // Free the memory allocated for the bucket array
    free(bucket);
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    // Read the elements from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}