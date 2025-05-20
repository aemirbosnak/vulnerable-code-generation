//Falcon-180B DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to initialize the array with random values
void init(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the array
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array using bubble sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the median of the array
double findMedian(int arr[], int size) {
    double median;
    int mid = size / 2;
    if (size % 2 == 0) {
        median = (arr[mid - 1] + arr[mid]) / 2;
    } else {
        median = arr[mid];
    }
    return median;
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Initialize the array with random values
    init(arr, size);

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    printf("Sorted array:\n");
    print(arr, size);

    // Find the median of the array
    double median = findMedian(arr, size);

    // Print the median
    printf("Median of the array: %lf\n", median);

    return 0;
}