//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Step 1: Create n empty buckets
    int i, j;
    float **buckets = (float**)malloc(n * sizeof(float*));
    int *count = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        count[i] = 0;
    }

    // Step 2: Insert elements into their respective buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]);  // Assuming arr[i] is in range [0, 1)
        if (bucketIndex >= n) bucketIndex = n - 1; // Edge case for max value
        buckets[bucketIndex][count[bucketIndex]++] = arr[i];
    }

    // Step 3: Sort individual buckets
    for (i = 0; i < n; i++) {
        // Use Insertion Sort for simplicity
        for (j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Step 4: Concatenate all buckets into arr
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Memory cleanup
    for (i = 0; i < n; i++)
        free(buckets[i]);
    free(buckets);
    free(count);
}

// Function to print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main function to drive the program
int main() {
    int n;

    printf("Welcome to the Bucket Sort Simulator!\n");
    printf("Please enter the number of elements (n): ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Number of elements should be greater than 0.\n");
        return 1;
    }

    float *arr = (float*)malloc(n * sizeof(float));
    
    printf("Enter %d floating-point numbers (range [0, 1)): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        // Validate range
        while (arr[i] < 0 || arr[i] >= 1) {
            printf("Please enter the number in range [0, 1): ");
            scanf("%f", &arr[i]);
        }
    }

    printf("Original array: \n");
    printArray(arr, n);
    
    // Perform Bucket Sort
    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Free allocated memory
    free(arr);
    
    printf("Thank you for using the Bucket Sort Simulator. Goodbye!\n");
    return 0;
}