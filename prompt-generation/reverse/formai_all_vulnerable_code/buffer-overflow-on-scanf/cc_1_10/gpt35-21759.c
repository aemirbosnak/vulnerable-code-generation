//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

// Function to print the matrix
void print_matrix(int rows, int cols, int arr[][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int rows, int cols, int arr1[][cols], int arr2[][cols], int res_arr[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res_arr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(int rows, int cols, int arr1[][cols], int arr2[][cols], int res_arr[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res_arr[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

// Function to find the product of two matrices
void multiply_matrices(int rows1, int cols1, int arr1[][cols1], int rows2, int cols2, int arr2[][cols2], int res_arr[][cols2]) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            res_arr[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                res_arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Verify if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible!\n");
        return 0;
    }

    int arr1[rows1][cols1], arr2[rows2][cols2], res_arr[rows1][cols2];
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Add two matrices
    add_matrices(rows1, cols1, arr1, arr2, res_arr);
    print_matrix(rows1, cols1, res_arr);

    // Subtract two matrices
    subtract_matrices(rows1, cols1, arr1, arr2, res_arr);
    print_matrix(rows1, cols1, res_arr);

    // Multiply two matrices
    multiply_matrices(rows1, cols1, arr1, rows2, cols2, arr2, res_arr);
    print_matrix(rows1, cols2, res_arr);

    return 0;
}