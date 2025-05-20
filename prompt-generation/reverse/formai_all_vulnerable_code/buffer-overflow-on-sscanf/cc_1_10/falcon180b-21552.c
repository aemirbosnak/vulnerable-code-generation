//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

int **create_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Error: Memory allocation failed.\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void destroy_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(const Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LINE_LEN];
    int rows, cols;
    Matrix m;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    fgets(input, MAX_LINE_LEN, stdin);
    sscanf(input, "%d", &rows);
    printf("Enter the number of columns: ");
    fgets(input, MAX_LINE_LEN, stdin);
    sscanf(input, "%d", &cols);

    // Create the matrix
    m.matrix = create_matrix(rows, cols);
    if (m.matrix == NULL) {
        return 1;
    }
    m.rows = rows;
    m.cols = cols;

    // Get the matrix elements from the user
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fgets(input, MAX_LINE_LEN, stdin);
            sscanf(input, "%d", &m.matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    print_matrix(&m);

    // Destroy the matrix
    destroy_matrix(m.matrix, m.rows);

    return 0;
}