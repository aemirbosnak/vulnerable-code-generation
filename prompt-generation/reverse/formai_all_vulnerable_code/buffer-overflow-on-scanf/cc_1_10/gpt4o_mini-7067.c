//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows, cols, choice;

    printf("Welcome to the Matrix Operations by Sherlock Holmes.\n");
    printf("In which realm of mathematics do you wish to explore today? (Please input the dimensions of your matrix)\n");

    // Input dimensions
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    printf("Now, valiant detective, please furnish the elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("\nExcellent! Now may I have the elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    do {
        printf("\nAh! The mysteries unfold further. What operation would you like to pursue?\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Print Matrices\n5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices(matrixA, matrixB, result, rows, cols);
                printf("The sum of Matrix A and Matrix B is:\n");
                printMatrix(result, rows, cols);
                break;

            case 2:
                subtractMatrices(matrixA, matrixB, result, rows, cols);
                printf("The difference of Matrix A and Matrix B is:\n");
                printMatrix(result, rows, cols);
                break;

            case 3:
                multiplyMatrices(matrixA, matrixB, result, rows, cols, cols);
                printf("The product of Matrix A and Matrix B is:\n");
                printMatrix(result, rows, cols);
                break;

            case 4:
                printf("Matrix A:\n");
                printMatrix(matrixA, rows, cols);
                printf("Matrix B:\n");
                printMatrix(matrixB, rows, cols);
                break;

            case 5:
                printf("Farewell, brave intellect! Until we meet again in the annals of logic.\n");
                break;

            default:
                printf("Hmm... that path seems illogical. Please enter a valid choice.\n");
        }

    } while (choice != 5);

    return 0;
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0; // Initialize the result
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}