//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

// function to add two matrices
void add(int m, int n, int matrix1[][n], int matrix2[][n]) {
    
    printf("Performing matrix addition...\n");

    // matrix to hold result
    int result[m][n];

    // loop through each element in matrix and add them
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // printing the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
void multiply(int m, int n, int p, int q, int matrix1[][n], int matrix2[][q]) {
    
    printf("Performing matrix multiplication...\n");

    // matrix to hold result
    int result[m][q];

    // initialize all elements to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            result[i][j] = 0;
        }
    }

    // loop through each row of matrix1
    for (int i = 0; i < m; i++) {

        // loop through each column of matrix2
        for (int j = 0; j < q; j++) {

            // loop through each element of row i in matrix1 and column j in matrix2
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // printing the result
    printf("Resultant Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, p, q;
    printf("Enter the number of rows and columns of matrix1: ");
    scanf("%d %d", &m, &n);
    int matrix1[m][n];
    printf("Enter the elements of matrix1:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the number of rows and columns of matrix2: ");
    scanf("%d %d", &p, &q);
    int matrix2[p][q];
    printf("Enter the elements of matrix2:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // checking if matrix addition is possible
    if (m == p && n == q) {
        add(m, n, matrix1, matrix2);
    }
    else {
        printf("Matrix addition is not possible as the number of rows and columns are not same for both matrices.\n");
    }

    // checking if matrix multiplication is possible
    if (n == p) {
        multiply(m, n, p, q, matrix1, matrix2);
    }
    else {
        printf("Matrix multiplication is not possible as the number of columns in matrix1 are not equal to the number of rows in matrix2.\n");
    }

    return 0;
}