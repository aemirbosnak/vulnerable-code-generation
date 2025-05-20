//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

void calculateStatistics(int *data, int size, double *mean, double *stdDev) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    *mean = sum / size;

    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow(data[i] - *mean, 2);
    }
    *stdDev = sqrt(variance / size);
}

void findOutliers(int *data, int size, double mean, double stdDev) {
    double lowerBound = mean - 2 * stdDev;
    double upperBound = mean + 2 * stdDev;

    printf("Outliers:\n");
    for (int i = 0; i < size; i++) {
        if (data[i] < lowerBound || data[i] > upperBound) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}

int main() {
    FILE *file;
    int data[MAX_SIZE];
    int size = 0;

    // Open the data file
    file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Read integers from file
    while (fscanf(file, "%d", &data[size]) == 1 && size < MAX_SIZE) {
        size++;
    }
    fclose(file);

    // Check if data was read
    if (size == 0) {
        fprintf(stderr, "No data read from file.\n");
        return EXIT_FAILURE;
    }

    // Calculate mean and standard deviation
    double mean, stdDev;
    calculateStatistics(data, size, &mean, &stdDev);

    // Display the calculated statistics
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stdDev);

    // Find and display outliers
    findOutliers(data, size, mean, stdDev);

    return EXIT_SUCCESS;
}