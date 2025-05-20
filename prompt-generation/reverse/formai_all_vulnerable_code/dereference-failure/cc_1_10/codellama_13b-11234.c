//Code Llama-13B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
/*
 * Levenshtein Distance Calculator
 * Synchronous Version
 *
 * This program calculates the Levenshtein distance between two strings.
 * It uses a synchronous approach, where the calculation is done
 * in a single thread.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the Levenshtein distance matrix
struct LevenshteinMatrix {
    int rows;
    int cols;
    int** matrix;
};

// Function to create a Levenshtein matrix
struct LevenshteinMatrix* createLevenshteinMatrix(int rows, int cols) {
    struct LevenshteinMatrix* matrix = malloc(sizeof(struct LevenshteinMatrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free a Levenshtein matrix
void freeLevenshteinMatrix(struct LevenshteinMatrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char* str1, char* str2) {
    int rows = strlen(str1) + 1;
    int cols = strlen(str2) + 1;
    struct LevenshteinMatrix* matrix = createLevenshteinMatrix(rows, cols);

    // Initialize the first row and column of the matrix
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i][0] = i;
    }
    for (int j = 0; j < cols; j++) {
        matrix->matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int min = matrix->matrix[i - 1][j - 1] + 1;
            if (str1[i - 1] != str2[j - 1]) {
                min = min < matrix->matrix[i - 1][j] ? min : matrix->matrix[i - 1][j];
                min = min < matrix->matrix[i][j - 1] ? min : matrix->matrix[i][j - 1];
            }
            matrix->matrix[i][j] = min;
        }
    }

    // Calculate the Levenshtein distance
    int distance = matrix->matrix[rows - 1][cols - 1];

    // Free the matrix
    freeLevenshteinMatrix(matrix);

    return distance;
}

int main() {
    char* str1 = "kitten";
    char* str2 = "sitting";
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    return 0;
}