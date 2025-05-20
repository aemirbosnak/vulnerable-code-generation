//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100  // Maximum numbers to sort
#define NUM_BUCKETS 10   // Number of buckets to use

// Function to print an array
void printArray(float arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // Create buckets
    float **buckets = (float **) malloc(NUM_BUCKETS * sizeof(float *));
    int *bucketCount = (int *) malloc(NUM_BUCKETS * sizeof(int));
    
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (float *) malloc(n * sizeof(float));
        bucketCount[i] = 0;
    }

    // Place elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * NUM_BUCKETS);
        if (bucketIndex >= NUM_BUCKETS) bucketIndex = NUM_BUCKETS - 1; // Cap at last bucket
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets and combine them
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        // Sort each bucket using simple insertion sort
        for (int j = 1; j < bucketCount[i]; j++) {
            float temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }

        // Combine the sorted buckets
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCount);
}

// Main function
int main() {
    printf("Welcome to the Bucket Sort Party!\n");
    printf("Let's sort some floating-point numbers! 🎉\n");

    float numbers[MAX_NUMBERS];
    int count;

    // Input the numbers
    printf("How many numbers would you like to sort (max %d)? ", MAX_NUMBERS);
    scanf("%d", &count);
    
    // Ensure the count does not exceed the maximum
    if (count > MAX_NUMBERS || count <= 0) {
        printf("Please enter a valid number of elements (1 to %d).\n", MAX_NUMBERS);
        return 1;
    }

    printf("Great! Please enter %d numbers (between 0.0 and 1.0):\n", count);
    for (int i = 0; i < count; i++) {
        scanf("%f", &numbers[i]);
        // Check range validity
        if (numbers[i] < 0.0 || numbers[i] > 1.0) {
            printf("Please enter numbers within 0.0 to 1.0 range, retry!\n");
            return 1;
        }
    }

    // Show the original array
    printArray(numbers, count);

    // Time to sort the numbers using the amazing bucket sort!
    bucketSort(numbers, count);

    // Show the sorted array
    printf("Yay! Here's your sorted array!\n");
    printArray(numbers, count);

    printf("Thank you for using our Bucket Sort Party! 🎊\n");
    return 0;
}