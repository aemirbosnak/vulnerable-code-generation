//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m, n;
    int *a;
} Matrix;

void printMatrix(Matrix m) {
    int i, j;
    for (i = 0; i < m.m; i++) {
        for (j = 0; j < m.n; j++) {
            printf("%d ", m.a[i * m.n + j]);
        }
        printf("\n");
    }
}

void transposeMatrix(Matrix *m) {
    int i, j;
    Matrix temp;

    temp.m = m->n;
    temp.n = m->m;
    temp.a = (int *)malloc(temp.m * temp.n * sizeof(int));

    for (i = 0; i < temp.m; i++) {
        for (j = 0; j < temp.n; j++) {
            temp.a[i * temp.n + j] = m->a[j * m->m + i];
        }
    }

    printf("Transpose of matrix:\n");
    printMatrix(temp);
}

int main() {
    int m, n, i, j;
    Matrix matrix;

    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    matrix.m = m;
    matrix.n = n;
    matrix.a = (int *)malloc(m * n * sizeof(int));

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix.a[i * n + j]);
        }
    }

    printf("Original matrix:\n");
    printMatrix(matrix);

    transposeMatrix(&matrix);

    return 0;
}