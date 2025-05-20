//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    int val;
} Cell;

void print_matrix(Cell matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j].val);
        }
        printf("\n");
    }
}

void generate_random_matrix(Cell matrix[][10], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j].val = rand() % 100;
        }
    }
}

void multiply_matrices(Cell A[][10], Cell B[][10], int k, int m, int n, Cell C[][10]) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j].val = 0;
            for (int l = 0; l < m; l++) {
                C[i][j].val += A[i][l].val * B[l][j].val;
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2, k;
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if (cols1!= rows2) {
        printf("Error: number of columns in first matrix must be equal to number of rows in second matrix\n");
        return 1;
    }
    Cell A[10][10], B[10][10], C[10][10];
    generate_random_matrix(A, rows1, cols1);
    generate_random_matrix(B, rows2, cols2);
    k = rows1;
    multiply_matrices(A, B, k, cols1, cols2, C);
    printf("Product of matrices:\n");
    print_matrix(C, k, cols2);
    return 0;
}