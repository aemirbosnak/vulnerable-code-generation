//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function prototypes
void displayMenu();
void executeOption(int choice);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2);
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);
void calculateDeterminant(int mat[MAX_SIZE][MAX_SIZE], int size);
void calculateInverse(int mat[MAX_SIZE][MAX_SIZE], float inverse[MAX_SIZE][MAX_SIZE], int size);
void fillMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        executeOption(choice);
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n==========================\n");
    printf("       Matrix Operations   \n");
    printf("==========================\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Transpose Matrix\n");
    printf("5. Calculate Determinant\n");
    printf("6. Calculate Inverse\n");
    printf("0. Exit\n");
}

void executeOption(int choice) {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    float inverse[MAX_SIZE][MAX_SIZE];
    int rows, cols, size;

    switch (choice) {
        case 1:
            printf("Enter rows and columns for the matrices: ");
            scanf("%d %d", &rows, &cols);
            printf("Fill first matrix:\n");
            fillMatrix(mat1, rows, cols);
            printf("Fill second matrix:\n");
            fillMatrix(mat2, rows, cols);
            addMatrices(mat1, mat2, result, rows, cols);
            printf("Resultant Matrix After Addition:\n");
            printMatrix(result, rows, cols);
            break;

        case 2:
            printf("Enter rows and columns for the matrices: ");
            scanf("%d %d", &rows, &cols);
            printf("Fill first matrix:\n");
            fillMatrix(mat1, rows, cols);
            printf("Fill second matrix:\n");
            fillMatrix(mat2, rows, cols);
            subtractMatrices(mat1, mat2, result, rows, cols);
            printf("Resultant Matrix After Subtraction:\n");
            printMatrix(result, rows, cols);
            break;

        case 3:
            printf("Enter rows and columns for first matrix: ");
            scanf("%d %d", &rows, &cols);
            printf("Fill first matrix:\n");
            fillMatrix(mat1, rows, cols);
            int cols2;
            printf("Enter columns for second matrix: ");
            scanf("%d", &cols2);
            printf("Fill second matrix:\n");
            fillMatrix(mat2, cols, cols2);
            multiplyMatrices(mat1, mat2, result, rows, cols, cols, cols2);
            printf("Resultant Matrix After Multiplication:\n");
            printMatrix(result, rows, cols2);
            break;

        case 4:
            printf("Enter rows and columns for the matrix: ");
            scanf("%d %d", &rows, &cols);
            printf("Fill the matrix:\n");
            fillMatrix(mat1, rows, cols);
            int transposed[MAX_SIZE][MAX_SIZE];
            transposeMatrix(mat1, transposed, rows, cols);
            printf("Transposed Matrix:\n");
            printMatrix(transposed, cols, rows);
            break;

        case 5:
            printf("Enter the size of the square matrix: ");
            scanf("%d", &size);
            printf("Fill the matrix:\n");
            fillMatrix(mat1, size, size);
            calculateDeterminant(mat1, size);
            break;

        case 6:
            printf("Enter the size of the square matrix: ");
            scanf("%d", &size);
            printf("Fill the matrix:\n");
            fillMatrix(mat1, size, size);
            calculateInverse(mat1, inverse, size);
            break;

        case 0:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
            break;
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

void calculateDeterminant(int mat[MAX_SIZE][MAX_SIZE], int size) {
    if (size == 1) {
        printf("Determinant: %d\n", mat[0][0]);
        return;
    }
    if (size == 2) {
        printf("Determinant: %d\n", mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
        return;
    }
    // Add more complex determinant calculation for larger matrices (not included for simplicity).
}

void calculateInverse(int mat[MAX_SIZE][MAX_SIZE], float inverse[MAX_SIZE][MAX_SIZE], int size) {
    // Inverse calculation logic (not included for simplicity).
    printf("Inverse calculation not implemented yet.\n");
}

void fillMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}