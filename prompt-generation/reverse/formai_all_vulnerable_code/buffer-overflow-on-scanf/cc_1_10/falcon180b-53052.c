//Falcon-180B DATASET v1.0 Category: Recursive ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to print the matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random matrix of given size
void generateMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    srand(time(0));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Recursive function to calculate the sum of elements in a given matrix
int sumMatrix(int matrix[MAX][MAX], int rows, int cols, int i, int j) {
    if (i >= rows || j >= cols) {
        return 0;
    }
    return matrix[i][j] + sumMatrix(matrix, rows, cols, i + 1, j) + sumMatrix(matrix, rows, cols, i, j + 1) - sumMatrix(matrix, rows, cols, i + 1, j + 1);
}

// Function to calculate the sum of elements in a given matrix
int calculateSum(int matrix[MAX][MAX], int rows, int cols) {
    return sumMatrix(matrix, rows, cols, 0, 0);
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[MAX][MAX];
    generateMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    int sum = calculateSum(matrix, rows, cols);
    printf("\nSum of elements in the matrix: %d\n", sum);

    return 0;
}