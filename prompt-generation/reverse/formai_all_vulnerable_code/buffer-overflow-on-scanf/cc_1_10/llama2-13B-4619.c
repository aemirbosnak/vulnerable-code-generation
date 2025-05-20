//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3 // number of matrices
#define N 4 // number of rows in each matrix
#define MATRIX_SIZE 4 // size of each matrix

typedef struct {
    int rows;
    int cols;
    int data[MATRIX_SIZE][MATRIX_SIZE];
} matrix;

void print_matrix(matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix *m1, matrix *m2, matrix *res) {
    int i, j;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            res->data[i][j] = m1->data[i][0] + m2->data[0][j];
        }
    }
}

void multiply_matrices(matrix *m1, matrix *m2, matrix *res) {
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            int sum = 0;
            for (k = 0; k < m1->cols; k++) {
                sum += m1->data[i][k] * m2->data[k][j];
            }
            res->data[i][j] = sum;
        }
    }
}

int main() {
    matrix m1, m2, res;
    int choice;

    // initialize matrices
    m1.rows = 3;
    m1.cols = 4;
    m1.data[0][0] = 1;
    m1.data[0][1] = 2;
    m1.data[0][2] = 3;
    m1.data[0][3] = 4;
    m1.data[1][0] = 5;
    m1.data[1][1] = 6;
    m1.data[1][2] = 7;
    m1.data[1][3] = 8;
    m1.data[2][0] = 9;
    m1.data[2][1] = 10;
    m1.data[2][2] = 11;
    m1.data[2][3] = 12;

    m2.rows = 3;
    m2.cols = 4;
    m2.data[0][0] = 13;
    m2.data[0][1] = 14;
    m2.data[0][2] = 15;
    m2.data[0][3] = 16;
    m2.data[1][0] = 17;
    m2.data[1][1] = 18;
    m2.data[1][2] = 19;
    m2.data[1][3] = 20;
    m2.data[2][0] = 21;
    m2.data[2][1] = 22;
    m2.data[2][2] = 23;
    m2.data[2][3] = 24;

    // menu for matrix operations
    printf("Welcome to the Matrix Operations Menu!\n");
    printf("Choose an operation and enter the corresponding number:\n");
    printf("1. Add two matrices\n");
    printf("2. Multiply two matrices\n");
    printf("3. Exit\n");

    // get user input
    scanf("%d", &choice);

    // perform operation based on user input
    if (choice == 1) {
        add_matrices(&m1, &m2, &res);
    } else if (choice == 2) {
        multiply_matrices(&m1, &m2, &res);
    }

    // print result
    print_matrix(&res);

    return 0;
}