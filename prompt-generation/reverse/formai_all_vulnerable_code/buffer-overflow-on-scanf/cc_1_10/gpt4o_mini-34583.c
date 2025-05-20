//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Function prototypes
void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2);
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c);

int main() 
{
    srand(time(NULL));
    
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // Matrix size input
    printf("Enter number of rows/columns for the square matrices (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    cols = rows;

    if (rows > MAX_SIZE) {
        printf("Size exceeds maximum limit of %d. Exiting.\n", MAX_SIZE);
        exit(1);
    }

    printf("Filling matrices with random values...\n");
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            a[i][j] = rand() % 10;

    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < cols; j++) 
            b[i][j] = rand() % 10;

    printf("Matrix A:\n");
    displayMatrix(a, rows, cols);
    
    printf("Matrix B:\n");
    displayMatrix(b, rows, cols);

    printf("Addition of A and B:\n");
    addMatrices(a, b, res, rows, cols);
    displayMatrix(res, rows, cols);
    
    printf("Subtraction of A and B:\n");
    subtractMatrices(a, b, res, rows, cols);
    displayMatrix(res, rows, cols);

    printf("Multiplication of A and B:\n");
    multiplyMatrices(a, b, res, rows, cols, cols);
    displayMatrix(res, rows, cols);

    printf("Transpose of Matrix A:\n");
    transposeMatrix(a, res, rows, cols);
    displayMatrix(res, cols, rows); // Note: transpose switches rows and cols

    printf("Transpose of Matrix B:\n");
    transposeMatrix(b, res, rows, cols);
    displayMatrix(res, cols, rows);

    return 0;
}

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
            printf("%d ", mat[i][j]);
        
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c) 
{
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            res[i][j] = a[i][j] + b[i][j];
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c) 
{
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            res[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r1, int c1, int c2) 
{
    for (int i = 0; i < r1; i++) 
        for (int j = 0; j < c2; j++) 
        {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) 
                res[i][j] += a[i][k] * b[k][j];
        }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int r, int c) 
{
    for (int i = 0; i < r; i++) 
        for (int j = 0; j < c; j++) 
            res[j][i] = mat[i][j];
}