//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10
#define N 8

// Matrix declarations
int mat[M][N] = {{1, 2, 3, 4, 5, 6, 7, 8},
                    {9, 10, 11, 12, 13, 14, 15, 16},
                    {17, 18, 19, 20, 21, 22, 23, 24},
                    {25, 26, 27, 28, 29, 30, 31, 32},
                    {33, 34, 35, 36, 37, 38, 39, 40},
                    {41, 42, 43, 44, 45, 46, 47, 48},
                    {49, 50, 51, 52, 53, 54, 55, 56}};

// Function declarations
void print_matrix(int mat[M][N]);
int sum_diag(int mat[M][N]);
int sum_row(int mat[M][N], int row);
int sum_col(int mat[M][N], int col);
int multiply(int mat[M][N], int mat2[M][N]);

int main() {
    int choice;
    int mat3[M][N];

    do {
        printf("Matrix Operations Menu\n");
        printf("1. Print Matrix\n");
        printf("2. Sum of Diagonal\n");
        printf("3. Sum of Row\n");
        printf("4. Sum of Column\n");
        printf("5. Multiply Matrices\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: print_matrix(mat); break;
            case 2: printf("Diagonal Sum: %d\n", sum_diag(mat)); break;
            case 3: printf("Row Sum: %d\n", sum_row(mat, 1)); break;
            case 4: printf("Column Sum: %d\n", sum_col(mat, 1)); break;
            case 5: {
                int mat4[M][N];
                multiply(mat, mat4);
                print_matrix(mat4);
                break;
            }
            case 6: exit(0);
        }
    } while (choice != 6);

    return 0;
}

// Print Matrix Function
void print_matrix(int mat[M][N]) {
    int i, j;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Sum of Diagonal Function
int sum_diag(int mat[M][N]) {
    int sum = 0;
    int i;

    for (i = 0; i < M; i++) {
        sum += mat[i][i];
    }

    return sum;
}

// Sum of Row Function
int sum_row(int mat[M][N], int row) {
    int sum = 0;
    int i;

    for (i = 0; i < N; i++) {
        sum += mat[row][i];
    }

    return sum;
}

// Sum of Column Function
int sum_col(int mat[M][N], int col) {
    int sum = 0;
    int i;

    for (i = 0; i < M; i++) {
        sum += mat[i][col];
    }

    return sum;
}

// Multiply Matrices Function
int multiply(int mat[M][N], int mat2[M][N]) {
    int mat3[M][N];
    int i, j, k;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int sum = 0;

            for (k = 0; k < N; k++) {
                sum += mat[i][k] * mat2[k][j];
            }

            mat3[i][j] = sum;
        }
    }

    return mat3;
}