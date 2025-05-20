//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

// Function to display matrix
void display_matrix(int m, int n, int matrix[m][n]) {
    printf("\nMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int m, int n, int matrix1[m][n], int matrix2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("\nResultant matrix after addition:\n");
    display_matrix(m, n, result);
}

// Function to transpose a matrix
void transpose_matrix(int m, int n, int matrix[m][n]) {
    int temp;
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    display_matrix(n, m, matrix);
}

// Function to multiply two matrices
void multiply_matrices(int m1, int n1, int matrix1[m1][n1], int m2, int n2, int matrix2[m2][n2]) {
    if (n1 != m2) {
        printf("\nMatrix multiplication not possible!\n");
        return;
    }
    int result[m1][n2];
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("\nResultant matrix after multiplication:\n");
    display_matrix(m1, n2, result);
}

int main() {
    int m1 = 3, n1 = 3;
    int m2 = 3, n2 = 3;
    int matrix1[m1][n1];
    int matrix2[m2][n2];
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    display_matrix(m1, n1, matrix1);
    printf("\nEnter elements of matrix 2:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    display_matrix(m2, n2, matrix2);
    int choice;
    do {
        printf("\nMenu:\n1. Add matrices\n2. Transpose matrix\n3. Multiply matrices\n4. Exit\nEnter your choice (1/2/3/4) : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int result[m1][n1];
                add_matrices(m1, n1, matrix1, matrix2, result);
                break;
            }
            case 2: {
                transpose_matrix(m2, n2, matrix2);
                break;
            }
            case 3: {
                multiply_matrices(m1, n1, matrix1, m2, n2, matrix2);
                break;
            }
            case 4: {
                printf("\nExiting...\n");
                break;
            }
            default: {
                printf("\nInvalid choice!\n");
            }
        }
    } while (choice != 4);
    return 0;
}