//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int **data;
    int rows;
    int cols;
} matrix;

void create_matrix(matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int*)malloc(cols * sizeof(int));
    }
}

void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    matrix m;
    create_matrix(&m, rows, cols);

    printf("Original matrix:\n");
    print_matrix(m);

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            m.data[i][j] = m.data[i][j] * 2;
        }
    }

    printf("\nModified matrix:\n");
    print_matrix(m);

    return 0;
}