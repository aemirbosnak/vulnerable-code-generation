//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000 // Maximum size of the array

// Function to initialize the array with random numbers
void init(int arr[], int size) {
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generate random number between 0 and 99
    }
}

// Function to sort the array using quicksort algorithm
void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2]; // Choose pivot element
    
    // Partition the array
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
    // Recursively sort the partitions
    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

// Function to calculate the sum of the elements in the array
int sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    init(arr, size); // Initialize the array with random numbers
    
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    quicksort(arr, 0, size - 1); // Sort the array
    
    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    int sumResult = sum(arr, size); // Calculate the sum of the elements in the array
    printf("\nSum of the elements: %d\n", sumResult);
    
    return 0;
}