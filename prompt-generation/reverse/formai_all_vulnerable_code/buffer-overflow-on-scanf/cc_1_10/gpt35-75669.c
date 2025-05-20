//FormAI DATASET v1.0 Category: Matrix operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Custom function for generating random matrices
void randomMatrix(int row, int col, int matrix[row][col]) {
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            matrix[i][j] = rand() % 10; // Random numbers between 0 to 9
        }
    }
}

// Custom function for displaying matrices
void displayMatrix(int row, int col, int matrix[row][col]) {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Custom function for matrix addition
void addMatrix(int row, int col, int a[row][col], int b[row][col], int sum[row][col]) {
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Custom function for matrix multiplication
void multiplyMatrix(int rowA, int colA, int rowB, int colB, int a[rowA][colA], int b[rowB][colB], int product[rowA][colB]) {
    if(colA != rowB) {
        printf("Cannot perform multiplication!\n"); // Error message if dimensions do not match
    } else {
        for(int i = 0; i < rowA; ++i) {
            for(int j = 0; j < colB; ++j) {
                product[i][j] = 0;
                for(int k = 0; k < colA; ++k) {
                    product[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
}

int main() {
    int rowA, colA, rowB, colB;
    printf("Enter the dimensions of matrix A (row col): ");
    scanf("%d %d", &rowA, &colA);
    printf("Enter the dimensions of matrix B (row col): ");
    scanf("%d %d", &rowB, &colB);
    
    // Validate the dimensions of matrices
    if(rowA < 1 || colA < 1 || rowB < 1 || colB < 1 || colA != rowB) {
        printf("Invalid dimensions!\n");
        return 1;
    }
    
    // Initialize matrices A and B
    int A[rowA][colA];
    int B[rowB][colB];
    printf("Initializing matrices...\n");
    randomMatrix(rowA, colA, A);
    displayMatrix(rowA, colA, A);
    printf("\n");
    randomMatrix(rowB, colB, B);
    displayMatrix(rowB, colB, B);
    printf("\n");
    
    // Add matrices A and B
    int sum[rowA][colA];
    printf("Adding matrices...\n");
    addMatrix(rowA, colA, A, B, sum);
    displayMatrix(rowA, colA, sum);
    printf("\n");
    
    // Multiply matrices A and B
    int product[rowA][colB];
    printf("Multiplying matrices...\n");
    multiplyMatrix(rowA, colA, rowB, colB, A, B, product);
    displayMatrix(rowA, colB, product);
    
    return 0;
}