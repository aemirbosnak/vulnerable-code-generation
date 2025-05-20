//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 1000
#define LOG_BASE 10

// Function declarations
void readData(double data[], int *size);
void calculateLogarithms(double data[], double logValues[], int size);
void printResults(double data[], double logValues[], int size);
void writeResultsToFile(double data[], double logValues[], int size, const char *filename);

int main() {
    double data[MAX_DATA_POINTS];
    double logValues[MAX_DATA_POINTS];
    int size = 0;

    readData(data, &size);
    calculateLogarithms(data, logValues, size);
    printResults(data, logValues, size);
    writeResultsToFile(data, logValues, size, "log_results.txt");

    return 0;
}

void readData(double data[], int *size) {
    printf("Enter the number of data points (max %d): ", MAX_DATA_POINTS);
    scanf("%d", size);
    
    if (*size > MAX_DATA_POINTS) {
        printf("Size exceeds maximum limit of %d. Setting to %d.\n", MAX_DATA_POINTS, MAX_DATA_POINTS);
        *size = MAX_DATA_POINTS;
    }

    printf("Enter %d data points (positive numbers only):\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%lf", &data[i]);
        if (data[i] <= 0) {
            printf("Invalid input (must be positive). Setting to 1 (log(1) = 0).\n");
            data[i] = 1.0;
        }
    }
}

void calculateLogarithms(double data[], double logValues[], int size) {
    for (int i = 0; i < size; i++) {
        logValues[i] = log(data[i]) / log(LOG_BASE); // Change the base with change in LOG_BASE
    }
}

void printResults(double data[], double logValues[], int size) {
    printf("\nData Points and their Logarithmic Values (Base %d):\n", LOG_BASE);
    printf("--------------------------------------------------\n");
    printf("|   Data   | Logarithm (Base %d) |\n", LOG_BASE);
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %8.2f | %20.6f |\n", data[i], logValues[i]);
    }
    printf("--------------------------------------------------\n");
}

void writeResultsToFile(double data[], double logValues[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "Data Points and their Logarithmic Values (Base %d)\n", LOG_BASE);
    fprintf(file, "--------------------------------------------------\n");
    fprintf(file, "|   Data   | Logarithm (Base %d) |\n", LOG_BASE);
    fprintf(file, "--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "| %8.2f | %20.6f |\n", data[i], logValues[i]);
    }
    fprintf(file, "--------------------------------------------------\n");

    fclose(file);
    printf("Results successfully wrote to %s\n", filename);
}