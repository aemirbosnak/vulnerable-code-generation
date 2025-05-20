//Falcon-180B DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int row;
    int col;
    int value;
} Cell;

Cell matrix[MAX_SIZE][MAX_SIZE];
int num_rows, num_cols;

void init_matrix(int r, int c) {
    num_rows = r;
    num_cols = c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j].row = i;
            matrix[i][j].col = j;
            matrix[i][j].value = rand() % 100;
        }
    }
}

void print_matrix() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", matrix[i][j].value);
        }
        printf("\n");
    }
}

void transpose_matrix() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            Cell temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void multiply_matrices(int a, int b, int c, int d) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                matrix[i][j].value += matrix[i][k].value * matrix[k][j].value;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d%d", &rows1, &cols1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d%d", &rows2, &cols2);
    if (cols1!= rows2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }
    init_matrix(rows1, cols1);
    init_matrix(rows2, cols2);
    print_matrix();
    transpose_matrix();
    print_matrix();
    multiply_matrices(rows1, cols1, rows2, cols2);
    print_matrix();
    return 0;
}