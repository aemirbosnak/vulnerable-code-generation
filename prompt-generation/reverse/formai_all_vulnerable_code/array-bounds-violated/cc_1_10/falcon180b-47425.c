//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>

#define ROW1 3
#define COL1 4
#define ROW2 4
#define COL2 3

void print_matrix(int matrix[][10], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[ROW1][COL1] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROW2][COL2] = {{10, 11}, {12, 13}, {14, 15}};
    int result[ROW1][COL2];

    // Addition
    int sum = 0;
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            sum = matrix1[i][j] + matrix2[i][j];
            result[i][j] = sum;
        }
    }
    printf("Addition:\n");
    print_matrix(result, ROW1, COL2);

    // Subtraction
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("Subtraction:\n");
    print_matrix(result, ROW1, COL2);

    // Multiplication
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL2; j++) {
            for (int k = 0; k < ROW2; k++) {
                sum = 0;
                for (int l = 0; l < COL1; l++) {
                    sum += matrix1[i][l] * matrix2[k][l];
                }
                result[i][j] = sum;
            }
        }
    }
    printf("Multiplication:\n");
    print_matrix(result, ROW1, COL2);

    // Transpose
    int transpose[COL1][ROW1];
    for (int i = 0; i < ROW1; i++) {
        for (int j = 0; j < COL1; j++) {
            transpose[j][i] = matrix1[i][j];
        }
    }
    printf("Transpose:\n");
    print_matrix(transpose, COL1, ROW1);

    return 0;
}