//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate random array of integers
void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

// Function to sort array using bitonic sort
void bitonicSort(int arr[], int size) {
    int gap = size / 2;
    for (int k = gap; k >= 1; k /= 2) {
        for (int i = 0; i < size; i += 2 * k) {
            int j = i + k - 1;
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int k = 1; k < size; k *= 2) {
        for (int i = 0; i < size; i += 2 * k) {
            int j = i + k - 1;
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];
    generateArray(arr, size);

    printf("Before sorting:\n");
    printArray(arr, size);

    bitonicSort(arr, size);

    printf("After sorting:\n");
    printArray(arr, size);

    return 0;
}