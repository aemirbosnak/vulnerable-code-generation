//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// Function to generate random integers
int generateRandomInt() {
    return rand() % MAX_SIZE;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create empty buckets
    int buckets[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = 0;
    }

    // Place elements in buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] % MAX_SIZE;
        buckets[bucketIndex]++;
    }

    // Place elements back into array
    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int k = 0; k < buckets[i]; k++) {
            arr[j++] = i;
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

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random integers and place them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = generateRandomInt();
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}