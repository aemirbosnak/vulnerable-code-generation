//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate a random number between 1 and MAX_SIZE
int generateRandomNumber() {
    return rand() % MAX_SIZE + 1;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int i, j, k;
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max - min + 1;

    // Create an array of buckets
    int* buckets = (int*) malloc(range * sizeof(int));

    // Initialize all buckets to 0
    for (i = 0; i < range; i++) {
        buckets[i] = 0;
    }

    // Place each element in its corresponding bucket
    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / range;
        buckets[bucketIndex]++;
    }

    // Modify the array to contain the sorted elements
    for (i = n - 1; i >= 0; i--) {
        int bucketIndex = (arr[i] - min) / range;
        for (j = 0; j < buckets[bucketIndex]; j++) {
            if (arr[i] == min + j * range) {
                swap(&arr[i], &arr[i - j]);
                break;
            }
        }
    }

    // Free the memory allocated for the buckets
    free(buckets);
}

int main() {
    int i, n;

    // Get the number of elements to sort from the user
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Generate an array of random numbers
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = generateRandomNumber();
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}