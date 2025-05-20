//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUCKETS 10 // Define the number of buckets
#define MAX_NUM 1.0    // Define the maximum number for our range
#define MIN_NUM 0.0    // Define the minimum number for our range

// Function to perform insertion sort on a bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create buckets
    float **buckets = malloc(NUM_BUCKETS * sizeof(float*));
    int *bucketSizes = calloc(NUM_BUCKETS, sizeof(int));

    // Initialize the buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = malloc(n * sizeof(float)); // Maximum size per bucket
    }

    // Distribute the input array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (NUM_BUCKETS * (arr[i] - MIN_NUM)) / (MAX_NUM - MIN_NUM); 
        if (index >= NUM_BUCKETS) index = NUM_BUCKETS - 1; // Handle edge case
        buckets[index][bucketSizes[index]] = arr[i];
        bucketSizes[index]++;
    }

    // Sort each bucket and merge results back into original array
    int k = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[k++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print an array
void printArray(float arr[], int n) {
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the bucket sort
int main() {
    // Performing an exhilarating array sorting experience!
    printf("Welcome to the Bucket Sort Implementation!\n");
    
    int n;
    printf("Enter the number of elements you want to sort (1 to 100): ");
    scanf("%d", &n);
    
    if(n < 1 || n > 100) {
        printf("Please enter a valid number of elements between 1 and 100.\n");
        return 1;
    }

    float arr[n];
    printf("Enter the elements (between %.1f and %.1f):\n", MIN_NUM, MAX_NUM);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        // Validating input
        if (arr[i] < MIN_NUM || arr[i] > MAX_NUM) {
            printf("Please enter a value between %.1f and %.1f.\n", MIN_NUM, MAX_NUM);
            return 1;
        }
    }

    printf("Before sorting:\n");
    printArray(arr, n);
    
    // Trigger the incredible sort!
    bucketSort(arr, n);
    
    // Present the astounding sorted array!
    printArray(arr, n);
    
    printf("Bucket Sort executed successfully! Happy coding!\n");
    return 0;
}