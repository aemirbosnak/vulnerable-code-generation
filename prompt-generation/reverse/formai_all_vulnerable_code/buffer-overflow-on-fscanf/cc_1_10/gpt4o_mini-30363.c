//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 1000

// Function to compare two numbers for qsort
int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

// Function to calculate the mean of the dataset
double calculate_mean(double *data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate the median of the dataset
double calculate_median(double *data, int size) {
    qsort(data, size, sizeof(double), compare);
    if (size % 2 == 0) {
        return (data[size / 2 - 1] + data[size / 2]) / 2.0;
    } else {
        return data[size / 2];
    }
}

// Function to calculate the standard deviation of the dataset
double calculate_std_dev(double *data, int size, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < size; i++) {
        sum_squared_diff += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum_squared_diff / size);
}

// Function to read data from file
int read_data(const char *filename, double *data) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return -1;
    }
    
    int count = 0;
    while (count < MAX_DATA_POINTS && fscanf(file, "%lf", &data[count]) == 1) {
        count++;
    }
    
    fclose(file);
    return count;
}

// Main function - entry point of the program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <data_file>\n", argv[0]);
        return 1;
    }

    double data[MAX_DATA_POINTS];
    int num_data_points = read_data(argv[1], data);
    
    if (num_data_points <= 0) {
        printf("No valid data points found in the file.\n");
        return 1;
    }

    double mean = calculate_mean(data, num_data_points);
    double median = calculate_median(data, num_data_points);
    double std_dev = calculate_std_dev(data, num_data_points, mean);

    printf("Data Statistics:\n");
    printf("Number of Data Points: %d\n", num_data_points);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Standard Deviation: %.2f\n", std_dev);

    return 0;
}