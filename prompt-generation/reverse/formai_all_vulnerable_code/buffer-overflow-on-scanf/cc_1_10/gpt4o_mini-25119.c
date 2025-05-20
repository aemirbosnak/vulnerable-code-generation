//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10  // Define bucket size based on the range of input
#define MAX_NUMBERS 100 // Maximum number of input numbers

// Function to perform insertion sort on a bucket
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create buckets
    int buckets[BUCKET_SIZE][MAX_NUMBERS];
    int bucketCount[BUCKET_SIZE];
    
    // Initialize bucket counts
    for (int i = 0; i < BUCKET_SIZE; i++) {
        bucketCount[i] = 0;
    }

    // Populate buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        buckets[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(buckets[i], bucketCount[i]);
            for (int j = 0; j < bucketCount[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int arr[MAX_NUMBERS];
    
    // Get the number of elements
    printf("Enter number of elements (up to %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    
    if (n > MAX_NUMBERS) {
        printf("Exceeded maximum limit of %d elements.\n", MAX_NUMBERS);
        return 1;
    }

    // Input elements
    printf("Enter %d numbers (range [0-%d]): \n", n, BUCKET_SIZE * BUCKET_SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] >= BUCKET_SIZE * BUCKET_SIZE) {
            printf("Please enter a number in range [0-%d].\n", BUCKET_SIZE * BUCKET_SIZE - 1);
            return 1;
        }
    }

    // Display original array
    printf("Original array: \n");
    printArray(arr, n);
    
    // Sort the array using bucket sort
    bucketSort(arr, n);
    
    // Display sorted array
    printArray(arr, n);
    
    return 0;
}