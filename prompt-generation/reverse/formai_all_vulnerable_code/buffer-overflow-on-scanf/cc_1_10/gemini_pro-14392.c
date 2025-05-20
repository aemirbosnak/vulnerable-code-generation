//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    Matrix *c = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

Matrix *subtract_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    Matrix *c = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return c;
}

Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        return NULL;
    }
    Matrix *c = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return c;
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    Matrix *a = create_matrix(rows1, cols1);
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &a->data[i][j]);
        }
    }
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    Matrix *b = create_matrix(rows2, cols2);
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &b->data[i][j]);
        }
    }

    Matrix *c;
    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add matrices\n");
        printf("2. Subtract matrices\n");
        printf("3. Multiply matrices\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                c = add_matrices(a, b);
                if (c == NULL) {
                    printf("Matrices cannot be added.\n");
                } else {
                    printf("The sum of the matrices is:\n");
                    print_matrix(c);
                    free_matrix(c);
                }
                break;
            case 2:
                c = subtract_matrices(a, b);
                if (c == NULL) {
                    printf("Matrices cannot be subtracted.\n");
                } else {
                    printf("The difference of the matrices is:\n");
                    print_matrix(c);
                    free_matrix(c);
                }
                break;
            case 3:
                c = multiply_matrices(a, b);
                if (c == NULL) {
                    printf("Matrices cannot be multiplied.\n");
                } else {
                    printf("The product of the matrices is:\n");
                    print_matrix(c);
                    free_matrix(c);
                }
                break;
            case 4:
                free_matrix(a);
                free_matrix(b);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}