//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000       // Maximum numbers to sort
#define BUCKET_SIZE 10         // Size of a single bucket for sorting
#define MAX_DIGITS 5           // Maximum digits for the numbers

// Function to find the maximum number in the array
int getMax(int arr[], int n) {
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create buckets
    int buckets[BUCKET_SIZE][MAX_NUMBERS];
    int bucketCount[BUCKET_SIZE] = {0};

    // Find the maximum value
    int maxValue = getMax(arr, n);
    
    // Map the values to the respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * BUCKET_SIZE) / (maxValue + 1);
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets and collect the results
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (bucketCount[i] > 0) {
            // Sort the bucket using insertion sort
            for (int j = 1; j < bucketCount[i]; j++) {
                int key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k = k - 1;
                }
                buckets[i][k + 1] = key;
            }
            // Collect the sorted elements from the bucket
            for (int j = 0; j < bucketCount[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate random test data
void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 to 999
    }
}

int main() {
    int arr[MAX_NUMBERS];
    int n;

    // Initialize random number generator
    srand(time(0));

    // Accept number of elements from the user
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    if (n > MAX_NUMBERS || n < 1) {
        printf("Invalid number of elements. Please enter a value between 1 and %d.\n", MAX_NUMBERS);
        return -1;
    }

    // Generate random numbers
    generateRandomNumbers(arr, n);

    // Print the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Perform bucket sort on the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}