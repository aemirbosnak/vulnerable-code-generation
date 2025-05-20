//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int m, n, i, j, k, l, c, d;
    int **A, **B, **C;

    // Allocate memory for matrices
    A = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    B = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        B[i] = (int *)malloc(n * sizeof(int));

    C = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
        C[i] = (int *)malloc(n * sizeof(int));

    // Get input from user
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d%d", &m, &n);

    // Get elements of first matrix
    printf("\nEnter the elements of first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Get elements of second matrix
    printf("\nEnter the elements of second matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Display the result
    printf("\nThe sum of the matrices is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for matrices
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }
        free(A);
        free(B);
        free(C);
    }

    return 0;
}