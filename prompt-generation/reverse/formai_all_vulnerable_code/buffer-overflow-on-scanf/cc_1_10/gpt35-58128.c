//FormAI DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>

void printMatrix(int r, int c, int mat[r][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int r, int c, int mat1[r][c], int mat2[r][c], int res[r][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int r, int c, int mat1[r][c], int mat2[r][c], int res[r][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int r1, int c1, int mat1[r1][c1], int r2, int c2, int mat2[r2][c2], int res[r1][c2]) {
    if(c1 != r2) {
        printf("Matrices cannot be multiplied!");
        return;
    }
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            res[i][j] = 0;
            for(int k=0; k<c1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter the number of rows and columns in matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns in matrix 2: ");
    scanf("%d %d", &r2, &c2);

    int mat1[r1][c1], mat2[r2][c2], res[r1][c2];
    printf("Enter the elements of matrix 1: \n");
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of matrix 2: \n");
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMatrix(r1, c1, mat1);
    printf("Matrix 2:\n");
    printMatrix(r2, c2, mat2);

    if(r1 == r2 && c1 == c2) {
        addMatrices(r1, c1, mat1, mat2, res);
        printf("Result after adding matrices:\n");
        printMatrix(r1, c1, res);

        subtractMatrices(r1, c1, mat1, mat2, res);
        printf("Result after subtracting matrices:\n");
        printMatrix(r1, c1, res);
    } else {
        printf("Matrices cannot be added or subtracted!\n");
    }

    if(c1 == r2) {
        multiplyMatrices(r1, c1, mat1, r2, c2, mat2, res);
        printf("Result after multiplying matrices:\n");
        printMatrix(r1, c2, res);
    } else {
        printf("Matrices cannot be multiplied!\n");
    }

    return 0;
}