//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h> // Required for exit() function
#include <stdbool.h> // Required for bool data type
#include <math.h> // Required for statistical functions such as sqrt()

int main() {
    FILE *fp; // File pointer variable
    double data[1000]; // Array to store data values
    int n = 0; // Number of data values read from file
    double sum = 0, mean = 0; // Variables for sum and mean
    double variance = 0, stdev = 0; // Variables for variance and standard deviation
    char *filename = "data.txt"; // File name

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read data values from file
    while (fscanf(fp, "%lf", &data[n]) != EOF) {
        sum += data[n]; // Add data value to sum
        n++; // Increment number of data values
    }

    // Calculate mean
    mean = sum / n;

    // Calculate variance and standard deviation
    for (int i = 0; i < n; i++) {
        variance += pow(data[i] - mean, 2);
    }
    variance /= n;
    stdev = sqrt(variance);

    // Close file
    fclose(fp);

    // Print statistical summary
    printf("Statistical summary for file '%s':\n", filename);
    printf("Number of values: %d\n", n);
    printf("Sum of values: %lf\n", sum);
    printf("Mean: %lf\n", mean);
    printf("Variance: %lf\n", variance);
    printf("Standard deviation: %lf\n", stdev);

    return 0;
}