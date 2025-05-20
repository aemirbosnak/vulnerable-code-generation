//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILENAME "data.txt"
#define MAX_ROWS 100
#define MAX_COLUMNS 10

float mean(float* array, int size);
float standard_deviation(float* array, int size, float mean);
void read_data(FILE* file, float data[MAX_ROWS][MAX_COLUMNS], int num_rows, int num_columns);
void print_data(float data[MAX_ROWS][MAX_COLUMNS], int num_rows, int num_columns);

int main() {
    FILE* file;
    float data[MAX_ROWS][MAX_COLUMNS] = {0};
    int num_rows = 0, num_columns = 0;
    float column_means[MAX_COLUMNS] = {0.0};
    float column_standard_deviations[MAX_COLUMNS] = {0.0};

    // Open file
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", FILENAME);
        return 1;
    }

    // Read data from file
    fscanf(file, "%d %d", &num_rows, &num_columns);
    read_data(file, data, num_rows, num_columns);
    fclose(file);

    // Calculate column means and standard deviations
    for (int i = 0; i < num_columns; ++i) {
        column_means[i] = mean(&data[0][i], num_rows);
        column_standard_deviations[i] = standard_deviation(&data[0][i], num_rows, column_means[i]);
    }

    // Print data
    printf("Data:\n");
    print_data(data, num_rows, num_columns);

    // Print column means and standard deviations
    printf("\nColumn means:\n");
    for (int i = 0; i < num_columns; ++i) {
        printf("Column %d: %f\n", i+1, column_means[i]);
    }
    printf("\nColumn standard deviations:\n");
    for (int i = 0; i < num_columns; ++i) {
        printf("Column %d: %f\n", i+1, column_standard_deviations[i]);
    }

    return 0;
}

// Calculates mean value for a given array
float mean(float* array, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

// Calculates standard deviation for a given array
float standard_deviation(float* array, int size, float mean) {
    float sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += pow(array[i] - mean, 2);
    }
    return sqrt(sum / size);
}

// Reads data from file and stores it in a 2D array
void read_data(FILE* file, float data[MAX_ROWS][MAX_COLUMNS], int num_rows, int num_columns) {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_columns; ++j) {
            fscanf(file, "%f", &data[i][j]);
        }
    }
}

// Prints data from a 2D array
void print_data(float data[MAX_ROWS][MAX_COLUMNS], int num_rows, int num_columns) {
    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_columns; ++j) {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
}