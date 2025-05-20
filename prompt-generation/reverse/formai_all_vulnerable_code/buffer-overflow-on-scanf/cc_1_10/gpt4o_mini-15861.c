//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_BUCKETS 10

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create an array of buckets
    int **buckets = (int **)malloc(NUM_BUCKETS * sizeof(int *));
    int *bucketCount = (int *)malloc(NUM_BUCKETS * sizeof(int));

    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketCount[i] = 0;
    }

    // Find the maximum element in the array
    int maxValue = getMax(arr, n);
    
    // Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int index = (NUM_BUCKETS * arr[i]) / (maxValue + 1);
        buckets[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    // Sort each bucket and then combine the buckets
    int k = 0;
    printf("Sorting buckets...\n");
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (bucketCount[i] > 0) {
            printf("Bucket %d: ", i);
            // Sort the current bucket using insertion sort
            for (int j = 0; j < bucketCount[i]; j++) {
                for (int l = 0; l < bucketCount[i] - j - 1; l++) {
                    if (buckets[i][l] > buckets[i][l + 1]) {
                        int temp = buckets[i][l];
                        buckets[i][l] = buckets[i][l + 1];
                        buckets[i][l + 1] = temp;
                    }
                }
            }

            // Print sorted bucket
            for (int j = 0; j < bucketCount[i]; j++) {
                printf("%d ", buckets[i][j]);
                arr[k++] = buckets[i][j]; // Copy the sorted bucket back to the original array
            }
            printf("\n");
        }
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCount);
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    printf("Welcome to the Exciting World of Bucket Sort!\n");

    int n;

    // Taking user input for array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    
    // Taking user input for array elements
    printf("Enter %d elements (0 to 100):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > 100) {
            printf("Please enter a value between 0 and 100.\n");
            i--; // To ensure we take the correct number of inputs
        }
    }

    displayArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array using Bucket Sort:\n");
    displayArray(arr, n);

    return 0;
}