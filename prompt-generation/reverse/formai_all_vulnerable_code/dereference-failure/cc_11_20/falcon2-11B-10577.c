//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5; // define the number of elements in the matrix
    int **matrix = malloc(n * sizeof(int*)); // allocate memory for the matrix
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int)); // allocate memory for each row of the matrix
    }
    
    // initialize the matrix with random values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    // perform matrix operations
    int *row = matrix[0]; // store the first row in a separate variable
    int *col = matrix[0][0]; // store the first column in a separate variable
    
    // print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // perform operations on the first row
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
        row[i] = sum;
    }
    
    // print the updated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // perform operations on the first column
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[j][i];
        }
        col[i] = sum;
    }
    
    // print the updated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // free the memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}