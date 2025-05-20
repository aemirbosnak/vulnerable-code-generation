//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int choice;
    int rowsA, colsA, rowsB, colsB;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];

    printf("In the realm of C-landia, two noble knights are ready to battle with matrices!\n");
    printf("Enter the number of rows and columns for the first knight's matrix: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Brave knight, enter the elements of matrix A:\n");
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsA; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("Now, enter the number of rows and columns for the second knight's matrix: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Gallant knight, enter the elements of matrix B:\n");
    for(int i = 0; i < rowsB; i++) {
        for(int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    do {
        printf("\nChoose your battle! What operation shall you perform?\n");
        printf("1. Add matrices\n");
        printf("2. Subtract matrices\n");
        printf("3. Multiply matrices\n");
        printf("4. Transpose matrix A\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(A, B, C, rowsA, colsA);
                    printf("Behold! The result of addition:\n");
                    displayMatrix(C, rowsA, colsA);
                } else {
                    printf("Alas! The dimensions of the matrices do not match for addition!\n");
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(A, B, C, rowsA, colsA);
                    printf("Behold! The result of subtraction:\n");
                    displayMatrix(C, rowsA, colsA);
                } else {
                    printf("Alas! The dimensions of the matrices do not match for subtraction!\n");
                }
                break;

            case 3:
                if (colsA == rowsB) {
                    multiplyMatrices(A, B, C, rowsA, colsA, rowsB, colsB);
                    printf("Behold! The result of multiplication:\n");
                    displayMatrix(C, rowsA, colsB);
                } else {
                    printf("Alas! The matrices cannot be multiplied due to incompatible dimensions!\n");
                }
                break;

            case 4:
                transposeMatrix(A, C, rowsA, colsA);
                printf("Behold! The transposed matrix A is:\n");
                displayMatrix(C, colsA, rowsA);
                break;

            case 5:
                printf("The knights shall retreat for now. Farewell!\n");
                break;

            default:
                printf("Noble knight, heed my words! Choose a correct option!\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for(int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            B[j][i] = A[i][j];
        }
    }
}