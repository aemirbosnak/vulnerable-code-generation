//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_VAL 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of an element in the array
int findIndex(int arr[], int n, int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int*) malloc(range * sizeof(int));
    for(int i=0; i<range; i++) {
        bucket[i] = 0;
    }
    for(int i=0; i<n; i++) {
        int index = (arr[i] - min) / (MAX_VAL / range);
        bucket[index]++;
    }
    for(int i=1; i<range; i++) {
        bucket[i] += bucket[i-1];
    }
    int *sorted = (int*) malloc(n * sizeof(int));
    for(int i=n-1; i>=0; i--) {
        int val = arr[i];
        int index = (val - min) / (MAX_VAL / range);
        sorted[--bucket[index]] = val;
    }
    for(int i=0; i<n; i++) {
        arr[i] = sorted[i];
    }
    free(bucket);
    free(sorted);
}

// Function to generate a random array of integers
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        arr[i] = rand() % MAX_VAL;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    generateArray(arr, n);
    printf("Original array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}