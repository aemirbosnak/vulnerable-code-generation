//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
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
    int max = findMax(arr, n);
    int* buckets = (int*) malloc(max * sizeof(int));

    // Initialize all buckets to empty
    for (int i = 0; i < max; i++) {
        buckets[i] = -1;
    }

    // Place each element in its respective bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / max;
        if (buckets[bucketIndex] == -1) {
            buckets[bucketIndex] = i;
        } else {
            int j = buckets[bucketIndex];
            while (j < i) {
                j += max;
            }
            buckets[bucketIndex] = j;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < max; i++) {
        if (buckets[i]!= -1) {
            arr[index++] = arr[buckets[i]];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));

    // Get the input array from the user
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}