//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define DIM_MAX 10

int main(void)
{
    int i, j, k;
    int dim_A, dim_B;
    int A[DIM_MAX][DIM_MAX];
    int B[DIM_MAX][DIM_MAX];
    int C[DIM_MAX][DIM_MAX];

    // Read matrix dimensions and elements
    do {
        printf("Enter the dimensions of matrix A (rows, columns): ");
        scanf("%d %d", &dim_A, &dim_B);
    } while (dim_A <= 0 || dim_A > DIM_MAX || dim_B <= 0 || dim_B > DIM_MAX);

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < dim_A; i++) {
        for (j = 0; j < dim_B; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read matrix dimensions and elements
    do {
        printf("Enter the dimensions of matrix B (rows, columns): ");
        scanf("%d %d", &dim_A, &dim_B);
    } while (dim_A <= 0 || dim_A > DIM_MAX || dim_B <= 0 || dim_B > DIM_MAX);

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < dim_A; i++) {
        for (j = 0; j < dim_B; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Check if matrices can be multiplied
    if (dim_B != dim_A) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    // Perform matrix multiplication
    for (i = 0; i < dim_A; i++) {
        for (j = 0; j < dim_B; j++) {
            C[i][j] = 0;
            for (k = 0; k < dim_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Result matrix:\n");
    for (i = 0; i < dim_A; i++) {
        for (j = 0; j < dim_B; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}