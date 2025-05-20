//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10 /* Maximum matrix size */

/* Function to read matrix size and elements */
void read_matrix(float a[][MAXSIZE], int m, int n) {
    int i, j;
    printf("Enter the matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
}

/* Function to display matrix elements */
void display_matrix(float a[][MAXSIZE], int m, int n) {
    int i, j;
    printf("Matrix elements are:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%7.2f", a[i][j]);
        }
        printf("\n");
    }
}

/* Function to multiply two matrices */
void multiply_matrices(float a[][MAXSIZE], float b[][MAXSIZE], float c[][MAXSIZE], int m, int n, int p) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m1, n1, m2, n2;
    float a[MAXSIZE][MAXSIZE], b[MAXSIZE][MAXSIZE], c[MAXSIZE][MAXSIZE];
    
    /* Read first matrix */
    printf("Enter the size of matrix 1 (row,column): ");
    scanf("%d,%d", &m1, &n1);
    read_matrix(a, m1, n1);
    
    /* Read second matrix */
    printf("Enter the size of matrix 2 (row,column): ");
    scanf("%d,%d", &m2, &n2);
    if (n1 != m2) {
        printf("Invalid matrix dimensions\n");
        return -1; /* Exit program with error */
    }
    read_matrix(b, m2, n2);
    
    /* Multiply matrices */
    multiply_matrices(a, b, c, m1, n1, n2);
    
    /* Display result matrix */
    display_matrix(c, m1, n2);
    
    return 0; /* Exit program */
}