//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef enum { 
    MAGIC_SQUARE, 
    ADD_ROW, 
    MULT_COL, 
    SQUARE_MATRIX, 
    FLIP_LR, 
    FLIP_UD 
} matrix_operation;

void print_matrix(int **matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** create_matrix(int rows, int cols) {
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void delete_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void magic_square(int **matrix, int rows, int cols) {
    // Create magic square using Siamese method
    int num = 1;
    int i = rows / 2;
    int j = cols - 1;
    while (num <= rows*cols) {
        if (i == -1 && j == cols) {
            j = cols - 2;
            i = 0;
        }
        else {
            if (j == cols) {
                j = 0;
            }
            if (i < 0) {
                i = rows - 1;
            }
        }
        if (matrix[i][j]) {
            j -= 2;
            i++;
            continue;
        }
        else {
            matrix[i][j] = num++;
        }
        j++;
        i--;
    }
}

void add_row(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += matrix[rows-1][j];
    }
    for (int j = 0; j < cols; j++) {
        matrix[rows-1][j] = sum + j;
    }
}

void mult_col(int **matrix, int rows, int cols) {
    int mult = 1;
    for (int i = 0; i < rows; i++) {
        mult *= matrix[i][0];
    }
    for (int i = 0; i < rows; i++) {
        matrix[i][0] = mult * i;
    }
}

void square_matrix(int **matrix, int rows, int cols) {
    if (rows != cols) {
        printf("ERROR: Matrix must be square for this operation\n");
        return;
    }
    int **result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * matrix[i][j];
        }
    }
    delete_matrix(matrix, rows);
    print_matrix(result, rows, cols);
}

void flip_lr(int **matrix, int rows, int cols) {
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][cols-j-1];
            matrix[i][cols-j-1] = temp;
        }
    }
}

void flip_ud(int **matrix, int rows, int cols) {
    int *temp;
    for (int i = 0; i < rows / 2; i++) {
        temp = matrix[i];
        matrix[i] = matrix[rows-i-1];
        matrix[rows-i-1] = temp;
    }
}

int main() {
    int rows, cols, op;
    printf("Enter number of rows and cols for matrix: ");
    scanf("%d %d", &rows, &cols);
    int **matrix = create_matrix(rows, cols);

    printf("Enter elements for matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Select matrix operation: \n");
    printf("1. Create magic square\n");
    printf("2. Add last row entries\n");
    printf("3. Multiply first column entries\n");
    printf("4. Create a square matrix (element-wise square)\n");
    printf("5. Flip matrix left-right\n");
    printf("6. Flip matrix up-down\n");
    scanf("%d", &op);

    switch (op) {
        case MAGIC_SQUARE:
            magic_square(matrix, rows, cols);
            break;
        case ADD_ROW:
            add_row(matrix, rows, cols);
            break;
        case MULT_COL:
            mult_col(matrix, rows, cols);
            break;
        case SQUARE_MATRIX:
            square_matrix(matrix, rows, cols);
            break;
        case FLIP_LR:
            flip_lr(matrix, rows, cols);
            break;
        case FLIP_UD:
            flip_ud(matrix, rows, cols);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    delete_matrix(matrix, rows);

    return 0;
}