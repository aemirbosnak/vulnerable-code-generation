//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// Function to generate a random number within the given range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int i, j, maxValue = generateRandomNumber(1, MAX_VALUE);
    int *bucket[MAX_VALUE];
    
    // Create empty buckets
    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = (int *)malloc(size * sizeof(int));
    }
    
    // Place elements into appropriate buckets
    for (i = 0; i < size; i++) {
        int index = arr[i] * maxValue / MAX_VALUE;
        bucket[index] = (int *)realloc(bucket[index], (size + 1) * sizeof(int));
        bucket[index][size] = arr[i];
    }
    
    // Sort the elements within each bucket
    for (i = 0; i < MAX_VALUE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < size; j++) {
                swap(&bucket[i][j], &bucket[i][j + 1]);
            }
        }
    }
    
    // Merge the sorted buckets back into the original array
    for (i = 0; i < MAX_VALUE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < size; j++) {
                arr[j] = bucket[i][j];
            }
        }
    }
    
    // Free memory allocated for the buckets
    for (i = 0; i < MAX_VALUE; i++) {
        if (bucket[i]!= NULL) {
            free(bucket[i]);
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, size;
    srand(time(NULL));
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[MAX_SIZE];
    
    // Populate the array with random numbers
    for (i = 0; i < size; i++) {
        arr[i] = generateRandomNumber(1, MAX_VALUE);
    }
    
    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);
    
    // Perform bucket sort
    bucketSort(arr, size);
    
    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);
    
    return 0;
}