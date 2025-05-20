//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main(){

// Declare variables
int rows_A, cols_A, rows_B, cols_B, i, j;

// Get user input for matrix A
printf("Enter number of rows for Matrix A: \n");
scanf("%d", &rows_A);

printf("Enter number of columns for Matrix A: \n");
scanf("%d", &cols_A);

// Allocate memory for matrix A dynamically
int **A = (int **)malloc(rows_A * sizeof(int *));
for(i = 0; i < rows_A; i++){
    A[i] = (int *)malloc(cols_A * sizeof(int));
}

// Get user input for values of matrix A
for(i = 0; i < rows_A; i++){
    for(j = 0; j < cols_A; j++){
        printf("Enter value for A[%d][%d]: ", i, j);
        scanf("%d", &A[i][j]);
    }
}

// Get user input for matrix B
printf("Enter number of rows for Matrix B: \n");
scanf("%d", &rows_B);

printf("Enter number of columns for Matrix B: \n");
scanf("%d", &cols_B);

// Allocate memory for matrix B dynamically
int **B = (int **)malloc(rows_B * sizeof(int *));
for(i = 0; i < rows_B; i++){
    B[i] = (int *)malloc(cols_B * sizeof(int));
}

// Get user input for values of matrix B
for(i = 0; i < rows_B; i++){
    for(j = 0; j < cols_B; j++){
        printf("Enter value for B[%d][%d]: ", i, j);
        scanf("%d", &B[i][j]);
    }
}

// Multiply Matrix A and Matrix B
if(cols_A != rows_B){
    printf("Matrix multiplication is not possible.\n");
}else{
    int **C = (int **)malloc(rows_A * sizeof(int *));
    for(i = 0; i < rows_A; i++){
        C[i] = (int *)malloc(cols_B * sizeof(int));
    }

    for(i = 0; i < rows_A; i++){
        for(j = 0; j < cols_B; j++){
            C[i][j] = 0;
            for(int k = 0; k < cols_A; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print Matrix C
    printf("\nMatrix C (result of Matrix A x Matrix B):\n");
    for(i = 0; i < rows_A; i++){
        for(j = 0; j < cols_B; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for(i = 0; i < rows_A; i++){
        free(A[i]);
    }
    free(A);

    for(i = 0; i < rows_B; i++){
        free(B[i]);
    }
    free(B);

    for(i = 0; i < rows_A; i++){
        free(C[i]);
    }
    free(C);
}

return 0;

}