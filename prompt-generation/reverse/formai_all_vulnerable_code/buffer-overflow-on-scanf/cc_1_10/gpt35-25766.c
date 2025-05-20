//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void sum_matrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract_matrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiply_matrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose_matrix(int A[][MAX_SIZE], int C[][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            C[j][i] = A[i][j];
        }
    }
}

int main() {
    printf("Welcome to the peaceful matrix operations program!\n");
    printf("Let's start by creating two matrices A and B.\n");
    
    int size;
    printf("Enter the size of the matrices (max size is %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    
    printf("Enter the elements of matrix A:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Enter the elements of matrix B:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    printf("Great! Now, let's perform some matrix operations.\n");
    
    // Matrix addition
    printf("Matrix addition:\n");
    sum_matrices(A, B, C, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    // Matrix subtraction
    printf("Matrix subtraction:\n");
    subtract_matrices(A, B, C, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    // Matrix multiplication
    printf("Matrix multiplication:\n");
    multiply_matrices(A, B, C, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    // Matrix transposition
    printf("Matrix transposition:\n");
    transpose_matrix(A, C, size);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    printf("Thank you for using the peaceful matrix operations program!\n");
    return 0;
}