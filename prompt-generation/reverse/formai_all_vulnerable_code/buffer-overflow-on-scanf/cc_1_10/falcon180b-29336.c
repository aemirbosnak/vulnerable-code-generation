//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandomArray(int* arr, int size);
void printArray(int* arr, int size);
double calculateAverage(int* arr, int size);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));
    generateRandomArray(arr, size);

    printf("Original array:\n");
    printArray(arr, size);

    double avg = calculateAverage(arr, size);
    printf("Average of the array: %lf\n", avg);

    free(arr);
    return 0;
}

// Function to generate a random array of integers
int generateRandomArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array of integers
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the average of an array of integers
double calculateAverage(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}