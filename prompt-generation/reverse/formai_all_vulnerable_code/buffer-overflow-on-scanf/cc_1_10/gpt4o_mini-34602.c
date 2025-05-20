//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 100

// Function prototypes
void fillArray(double arr[], int size);
void printArray(double arr[], int size);
double calculateMean(double arr[], int size);
double calculateVariance(double arr[], int size, double mean);
double calculateStandardDeviation(double variance);
void sortArray(double arr[], int size);
void displayHistogram(double arr[], int size, int bins);

int main() {
    double data[MAX_ELEMENTS];
    int numElements, bins;

    // User input for the number of elements
    printf("Enter the number of elements (max %d): ", MAX_ELEMENTS);
    scanf("%d", &numElements);

    // Ensure proper range
    if (numElements <= 0 || numElements > MAX_ELEMENTS) {
        printf("Error: Please enter a number between 1 and %d\n", MAX_ELEMENTS);
        return 1;
    }

    // Fill the array with random numbers
    fillArray(data, numElements);
    
    // Calculate statistical measures
    double mean = calculateMean(data, numElements);
    double variance = calculateVariance(data, numElements, mean);
    double stdDev = calculateStandardDeviation(variance);

    // Output the results
    printf("\nArray of elements:\n");
    printArray(data, numElements);
    printf("\nMean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stdDev);

    // User input for histogram bins
    printf("Enter the number of bins for histogram (recommended <= 20): ");
    scanf("%d", &bins);
    if (bins <= 0 || bins > 20) {
        printf("Error: Please enter a number between 1 and 20.\n");
        return 1;
    }

    // Display the histogram
    printf("\nHistogram of elements:\n");
    displayHistogram(data, numElements, bins);

    return 0;
}

// Function to fill array with random numbers
void fillArray(double arr[], int size) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = (double)(rand() % 10000) / 100; // Random float between 0.0 and 99.99
    }
}

// Function to print array
void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the mean
double calculateMean(double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the variance
double calculateVariance(double arr[], int size, double mean) {
    double varianceSum = 0.0;
    for (int i = 0; i < size; i++) {
        varianceSum += pow(arr[i] - mean, 2);
    }
    return varianceSum / size;
}

// Function to calculate the standard deviation
double calculateStandardDeviation(double variance) {
    return sqrt(variance);
}

// Function to sort the array using bubble sort
void sortArray(double arr[], int size) {
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

// Function to display the histogram
void displayHistogram(double arr[], int size, int bins) {
    // Sort the array first
    sortArray(arr, size);

    double minValue = arr[0];
    double maxValue = arr[size - 1];
    double binWidth = (maxValue - minValue) / bins;
    int histogram[bins];

    // Initialize histogram bins
    for (int i = 0; i < bins; i++) {
        histogram[i] = 0;
    }

    // Fill the histogram
    for (int i = 0; i < size; i++) {
        int binIndex = (arr[i] - minValue) / binWidth;
        if (binIndex >= bins) {
            binIndex = bins - 1; // Push value into the last bin if it's at max
        }
        histogram[binIndex]++;
    }

    // Print the histogram
    for (int i = 0; i < bins; i++) {
        printf("Bin %2d (%.2f - %.2f): ", i + 1, minValue + i * binWidth, minValue + (i + 1) * binWidth);
        for (int j = 0; j < histogram[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", histogram[i]);
    }
}