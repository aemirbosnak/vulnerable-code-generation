//FormAI DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// This is a program for performing matrix operations in C
// It is imperative that we solve this mystery and find the solution to this matrix problem
// It is elementary, my dear Watson!

int main() {
    int r1, c1, r2, c2, i, j, k;
    int sum = 0;
    char *matrix_type;
    int **a, **b, **result;

    printf("Enter the type of matrix: ");
    scanf("%s", matrix_type);

    printf("Enter the number of rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    // Creating dynamic memory allocation for matrix A
    a = (int **) malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
        a[i] = (int *) malloc(c1 * sizeof(int));

    printf("Enter elements of Matrix A: \n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the number of rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    // Creating dynamic memory allocation for matrix B
    b = (int **) malloc(r2 * sizeof(int *));
    for (i = 0; i < r2; i++)
        b[i] = (int *) malloc(c2 * sizeof(int));

    printf("Enter elements of Matrix B: \n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Error Handling for matrix multiplication
    if (c1 != r2) {
        printf("Matrix multiplication not possible!");
        exit(0);
    }

    // Creating dynamic memory allocation for result matrix
    result = (int **) malloc(r1 * sizeof(int *));
    for (i = 0; i < r2; i++)
        result[i] = (int *) malloc(c2 * sizeof(int));

    // Matrix Multiplication using nested loops
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < r2; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }

    printf("Result of Matrix Multiplication: \n");

    // Displaying the result matrix
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Freeing the dynamic memory allocation
    for (i = 0; i < r1; i++)
        free(a[i]);
    free(a);

    for (i = 0; i < r2; i++)
        free(b[i]);
    free(b);

    for (i = 0; i < r1; i++)
        free(result[i]);
    free(result);

    printf("Elementary, my dear Watson!");
    return 0;
}