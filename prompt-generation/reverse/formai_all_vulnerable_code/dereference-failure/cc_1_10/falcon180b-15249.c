//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));

    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[j] = i + min;
        }
    }

    free(bucket);
}

// Function to generate random numbers
void generateRandom(int arr[], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    generateRandom(arr, n);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}