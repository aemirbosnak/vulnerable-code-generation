//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>

#define MAX_SIZE 10

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nMatrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nAdding matrices:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    print_matrix(result, rows, cols);
}

void subtract_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\nSubtracting matrices:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    print_matrix(result, rows, cols);
}

void multiply_matrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    printf("\nMultiplying matrices:\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    print_matrix(result, rows1, cols2);
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, rows2, cols1, cols2;
    
    printf("Enter rows and columns of matrix 1 (<= 10): ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter elements of matrix 1:\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("Enter rows and columns of matrix 2 (<= 10): ");
    scanf("%d %d", &rows2, &cols2);
    
    printf("Enter elements of matrix 2:\n");
    for(int i = 0; i < rows2; i++) {
        for(int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    if(rows1 != rows2 || cols1 != cols2) {
        printf("\nError: Matrices are not of the same size.\n");
        return 0;
    }
    
    printf("\nOperations:\n1. Add matrices\n2. Subtract matrices\n3. Multiply matrices\nEnter your choice (1-3): ");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            add_matrices(matrix1, matrix2, result, rows1, cols1);
            break;
        case 2:
            subtract_matrices(matrix1, matrix2, result, rows1, cols1);
            break;
        case 3:
            multiply_matrices(matrix1, matrix2, result, rows1, cols1, cols2);
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}