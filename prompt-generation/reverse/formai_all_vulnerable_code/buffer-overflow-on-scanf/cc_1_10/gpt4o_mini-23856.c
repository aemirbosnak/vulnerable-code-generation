//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputNumbers(double *arr, int size, int index);
double calculateMean(double *arr, int size);
void sortArray(double *arr, int size);
double calculateMedian(double *arr, int size);
double calculateStandardDeviation(double *arr, double mean, int size);

int main() {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("The number of elements must be positive.\n");
        return 1;
    }
    
    double *arr = (double *)malloc(size * sizeof(double));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input numbers into the array recursive
    inputNumbers(arr, size, 0);

    // Calculate statistics
    double mean = calculateMean(arr, size);
    sortArray(arr, size);
    double median = calculateMedian(arr, size);
    double stdDev = calculateStandardDeviation(arr, mean, size);

    // Output results
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", stdDev);

    // Free allocated memory
    free(arr);

    return 0;
}

// Recursive function to input numbers
void inputNumbers(double *arr, int size, int index) {
    if (index < size) {
        printf("Enter number %d: ", index + 1);
        scanf("%lf", &arr[index]);
        inputNumbers(arr, size, index + 1);
    }
}

// Function to calculate the mean
double calculateMean(double *arr, int size) {
    if (size == 0) return 0;
    return (arr[size - 1] + ((size - 1) * calculateMean(arr, size - 1))) / size;
}

// Function to sort the array (Bubble Sort)
void sortArray(double *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the median
double calculateMedian(double *arr, int size) {
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Function to calculate the standard deviation
double calculateStandardDeviation(double *arr, double mean, int size) {
    if (size == 0) return 0;
    double variance = ((arr[size - 1] - mean) * (arr[size - 1] - mean) + (size - 1) * calculateStandardDeviation(arr, mean, size - 1)) / size;
    return sqrt(variance);
}