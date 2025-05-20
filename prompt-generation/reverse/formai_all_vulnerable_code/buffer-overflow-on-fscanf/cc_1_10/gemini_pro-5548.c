//GEMINI-pro DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store a row of data
typedef struct {
    double x;
    double y;
    double z;
} DataRow;

// Function to read a row of data from a file
int readRow(FILE *fp, DataRow *row) {
    return fscanf(fp, "%lf %lf %lf", &row->x, &row->y, &row->z);
}

// Function to write a row of data to a file
int writeRow(FILE *fp, DataRow *row) {
    return fprintf(fp, "%lf %lf %lf\n", row->x, row->y, row->z);
}

// Function to print a row of data to the console
void printRow(DataRow *row) {
    printf("%lf %lf %lf\n", row->x, row->y, row->z);
}

// Function to read a matrix of data from a file
int readMatrix(FILE *fp, DataRow **matrix, int nrows, int ncols) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (readRow(fp, &matrix[i][j]) != 3) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to write a matrix of data to a file
int writeMatrix(FILE *fp, DataRow **matrix, int nrows, int ncols) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (writeRow(fp, &matrix[i][j]) != 3) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to print a matrix of data to the console
void printMatrix(DataRow **matrix, int nrows, int ncols) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printRow(&matrix[i][j]);
        }
    }
}

// Function to free the memory allocated for a matrix of data
void freeMatrix(DataRow **matrix, int nrows) {
    for (int i = 0; i < nrows; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

// Main function
int main() {
    // Open the input file
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Read the number of rows and columns in the matrix
    int nrows, ncols;
    fscanf(fp, "%d %d", &nrows, &ncols);

    // Allocate memory for the matrix
    DataRow **matrix = malloc(nrows * sizeof(DataRow *));
    for (int i = 0; i < nrows; i++) {
        matrix[i] = malloc(ncols * sizeof(DataRow));
    }

    // Read the matrix from the file
    if (!readMatrix(fp, matrix, nrows, ncols)) {
        perror("Error reading matrix from file");
        freeMatrix(matrix, nrows);
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Close the input file
    fclose(fp);

    // Print the matrix to the console
    printMatrix(matrix, nrows, ncols);

    // Open the output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening output file");
        freeMatrix(matrix, nrows);
        return EXIT_FAILURE;
    }

    // Write the matrix to the file
    if (!writeMatrix(fp, matrix, nrows, ncols)) {
        perror("Error writing matrix to file");
        freeMatrix(matrix, nrows);
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Close the output file
    fclose(fp);

    // Free the memory allocated for the matrix
    freeMatrix(matrix, nrows);

    return EXIT_SUCCESS;
}