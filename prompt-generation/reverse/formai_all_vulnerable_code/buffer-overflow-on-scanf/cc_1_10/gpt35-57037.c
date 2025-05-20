//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>

// Function to read matrix elements
void readMatrix(int arr[][100], int row, int col) {
    printf("Enter elements of matrix:\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

// Function to print matrix elements
void printMatrix(int arr[][100], int row, int col) {
    printf("Matrix elements:\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int arr1[][100], int arr2[][100], int res[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Function to subtract two matrices
void subMatrix(int arr1[][100], int arr2[][100], int res[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

// Function to multiply two matrices
void mulMatrix(int arr1[][100], int arr2[][100], int res[][100], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            res[i][j] = 0;

            for (int k = 0; k < col1; k++) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    int arr1[100][100], arr2[100][100], res[100][100];
    int row1, col1, row2, col2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Checking if matrices can be added, subtracted or multiplied
    if (row1 != row2 || col1 != col2) {
        printf("Matrices cannot be added, subtracted or multiplied!\n");
        return 0;
    }

    // Reading matrices
    readMatrix(arr1, row1, col1);
    readMatrix(arr2, row2, col2);

    // Printing matrices
    printMatrix(arr1, row1, col1);
    printMatrix(arr2, row2, col2);

    // Adding matrices
    addMatrix(arr1, arr2, res, row1, col1);
    printf("Addition of two matrices:\n");
    printMatrix(res, row1, col1);

    // Subtracting matrices
    subMatrix(arr1, arr2, res, row1, col1);
    printf("Subtraction of two matrices:\n");
    printMatrix(res, row1, col1);

    // Multiplying matrices
    mulMatrix(arr1, arr2, res, row1, col1, row2, col2);
    printf("Multiplication of two matrices:\n");
    printMatrix(res, row1, col2);

    return 0;
}