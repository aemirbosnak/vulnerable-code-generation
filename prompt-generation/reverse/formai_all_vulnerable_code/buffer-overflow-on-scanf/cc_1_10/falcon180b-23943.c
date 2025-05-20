//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30

void generate_matrix(int **matrix, int rows, int cols);
void print_matrix(int **matrix, int rows, int cols);
int sum_matrix_elements(int **matrix, int rows, int cols);

int main() {
    srand(time(0));
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Invalid input. The number of rows and columns must be between 1 and %d.\n", MAX_ROWS * MAX_COLS);
        return 1;
    }

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    generate_matrix(matrix, rows, cols);
    printf("Generated matrix:\n");
    print_matrix(matrix, rows, cols);

    int sum = sum_matrix_elements(matrix, rows, cols);
    printf("The sum of all elements in the matrix is: %d\n", sum);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void generate_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int sum_matrix_elements(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}