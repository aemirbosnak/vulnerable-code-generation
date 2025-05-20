//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUMBERS 100

void populateArray(double arr[], int size) {
    srand(time(NULL)); // Seed for random numbers
    for (int i = 0; i < size; i++) {
        arr[i] = ((double)rand() / RAND_MAX) * 100; // Fill with random numbers from 0 to 100
    }
}

void printArray(double arr[], int size) {
    printf("Array contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

double computeMean(double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

double computeMedian(double arr[], int size) {
    // First sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2;
    } else {
        return arr[size / 2];
    }
}

double computeMode(double arr[], int size) {
    int count[MAX_NUMBERS] = {0};  // To count occurrences of numbers
    int maxCount = 0;
    double mode = arr[0];

    for (int i = 0; i < size; i++) {
        int index = (int)arr[i];
        count[index]++;
        if (count[index] > maxCount) {
            maxCount = count[index];
            mode = arr[i];
        }
    }
    return mode;
}

double computeStandardDeviation(double arr[], int size, double mean) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / size);
}

int main() {
    double numbers[MAX_NUMBERS];
    int numCount;

    do {
        printf("Enter the number of random numbers you want (between 1 and %d): ", MAX_NUMBERS);
        scanf("%d", &numCount);
    } while (numCount < 1 || numCount > MAX_NUMBERS);

    populateArray(numbers, numCount);
    printArray(numbers, numCount);

    double mean = computeMean(numbers, numCount);
    printf("Mean: %.2f\n", mean);

    double median = computeMedian(numbers, numCount);
    printf("Median: %.2f\n", median);
    
    double mode = computeMode(numbers, numCount);
    printf("Mode: %.2f\n", mode);

    double stdDev = computeStandardDeviation(numbers, numCount, mean);
    printf("Standard Deviation: %.2f\n", stdDev);

    // Additional calculations for variance
    double variance = pow(stdDev, 2);
    printf("Variance: %.2f\n", variance);

    // Show the range of the data
    double min = numbers[0];
    double max = numbers[0];
    for (int i = 1; i < numCount; i++) {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
    }
    printf("Range: %.2f - %.2f\n", min, max);

    // Display sorted data
    printf("Sorted Data: ");
    for (int i = 0; i < numCount; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    return 0;
}