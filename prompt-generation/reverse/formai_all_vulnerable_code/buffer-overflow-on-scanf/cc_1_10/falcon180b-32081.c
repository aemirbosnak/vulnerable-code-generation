//Falcon-180B DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL 100

// Function to generate random matrix
void generate_matrix(int rows, int cols, int mat[MAX_ROWS][MAX_COLS]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % MAX_VAL;
        }
    }
}

// Function to print matrix
void print_matrix(int rows, int cols, int mat[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose matrix
void transpose_matrix(int rows, int cols, int mat[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

// Function to calculate sum of matrix elements
int sum_matrix(int rows, int cols, int mat[MAX_ROWS][MAX_COLS]) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
    }
    return sum;
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix dimensions exceed maximum limit.\n");
        return 1;
    }

    int mat[MAX_ROWS][MAX_COLS];
    generate_matrix(rows, cols, mat);
    printf("Original matrix:\n");
    print_matrix(rows, cols, mat);

    int sum = sum_matrix(rows, cols, mat);
    printf("Sum of matrix elements: %d\n", sum);

    transpose_matrix(rows, cols, mat);
    printf("Transposed matrix:\n");
    print_matrix(cols, rows, mat);

    return 0;
}