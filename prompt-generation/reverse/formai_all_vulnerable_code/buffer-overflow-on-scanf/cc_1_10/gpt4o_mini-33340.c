//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void calculateMean(int *arr, int n, double *mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    *mean = sum / n;
}

void calculateMedian(int *arr, int n, double *median) {
    // Sort array to find median
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (n % 2 == 0) {
        *median = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        *median = arr[n/2];
    }
}

void calculateStandardDeviation(int *arr, int n, double mean, double *stddev) {
    double sum_of_squares = 0.0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += (arr[i] - mean) * (arr[i] - mean);
    }
    *stddev = sqrt(sum_of_squares / n);
}

void printArray(int *arr, int n) {
    printf("Generated numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Welcome to the Random Number Statistics Program!\n");
    printf("How many random integers do you want to generate? ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand(time(0));  // Seed the random number generator

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generate numbers between 0 and 99
    }

    double mean, median, stddev;

    calculateMean(arr, n, &mean);
    calculateMedian(arr, n, &median);
    calculateStandardDeviation(arr, n, mean, &stddev);

    printArray(arr, n);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", stddev);

    free(arr);  // Free allocated memory
    return 0;
}