//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 4
#define COL 4

void input_matrix(int matrix[ROW][COL]) {
    printf("Enter the elements of the matrix:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int matrix[ROW][COL]) {
    printf("The entered matrix is:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROW][COL];
    input_matrix(matrix);
    display_matrix(matrix);

    int sum_matrix[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            sum_matrix[i][j] = matrix[i][j] + matrix[i][j];
        }
    }
    printf("\nSum of the matrix:\n");
    display_matrix(sum_matrix);

    int product_matrix[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            product_matrix[i][j] = matrix[i][j] * matrix[i][j];
        }
    }
    printf("\nProduct of the matrix:\n");
    display_matrix(product_matrix);

    int transpose_matrix[COL][ROW];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            transpose_matrix[j][i] = matrix[i][j];
        }
    }
    printf("\nTranspose of the matrix:\n");
    display_matrix(transpose_matrix);

    int determinant;
    if(ROW == COL) {
        determinant = matrix[0][0] * matrix[1][1] * matrix[2][2] * matrix[3][3] - matrix[0][1] * matrix[1][2] * matrix[2][3] * matrix[3][0] + matrix[0][2] * matrix[1][3] * matrix[2][0] * matrix[3][1] - matrix[0][3] * matrix[1][0] * matrix[2][1] * matrix[3][2];
        printf("\nDeterminant of the matrix: %d", determinant);
    }
    else {
        printf("\nDeterminant of the matrix is not possible.");
    }

    return 0;
}