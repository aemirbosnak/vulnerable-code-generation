//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to bubble sort an array of integers
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to print an array of integers
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    srand(time(NULL)); // seed the random number generator
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // randomize the elements of the array
    }
    
    printf("Array before sorting:\n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Array after sorting:\n");
    printArray(arr, n);
    
    return 0;
}