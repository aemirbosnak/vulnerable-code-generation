//Falcon-180B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to print a matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int newMatrix[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[j][i];
        }
    }
}

int main() {
    int rows, cols;
    
    // get matrix dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // create matrix with random numbers
    int matrix[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = getRandomNumber(1, 100);
        }
    }
    
    // print original matrix
    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols);
    
    // transpose matrix
    transposeMatrix(matrix, rows, cols);
    
    // print transposed matrix
    printf("Transposed matrix:\n");
    printMatrix(matrix, cols, rows);
    
    return 0;
}