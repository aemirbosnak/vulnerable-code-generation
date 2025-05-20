//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void generate_matrix(int mat[MAX][MAX], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int mat[MAX][MAX], int n) {
    int temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = temp[i][j];
        }
    }
}

void multiply_matrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int res[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    int mat1[MAX][MAX], mat2[MAX][MAX], res[MAX][MAX];

    generate_matrix(mat1, n);
    print_matrix(mat1, n);

    generate_matrix(mat2, n);
    print_matrix(mat2, n);

    transpose_matrix(mat2, n);
    print_matrix(mat2, n);

    multiply_matrices(mat1, mat2, res, n);
    printf("Result of matrix multiplication:\n");
    print_matrix(res, n);

    return 0;
}