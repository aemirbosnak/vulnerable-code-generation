//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to my Matrix operations program, I am grateful to guide you through it!\n");
    printf("This program performs basic matrix operations such as addition, subtraction, and multiplication.\n");

    int m, n, p, q;

    printf("Enter the number of rows of matrix A: ");
    scanf("%d", &m);
    printf("Enter the number of columns of matrix A: ");
    scanf("%d", &n);

    printf("Enter the number of rows of matrix B: ");
    scanf("%d", &p);
    printf("Enter the number of columns of matrix B: ");
    scanf("%d", &q);

    if (n != p) {
        printf("The number of columns of matrix A must be equal to the number of rows of matrix B. Aborting program.");
        exit(0);
    }

    int a[m][n], b[p][q], c[m][q];
    int i, j, k;

    printf("\nEnter the elements of matrix A:\n");

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            printf("Element[%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the elements of matrix B:\n");

    for (i=0; i<p; i++) {
        for (j=0; j<q; j++) {
            printf("Element[%d][%d]: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    // Addition of matrices A and B
    printf("\nPerforming matrix addition...\n");

    for (i=0; i<m; i++) {
        for (j=0; j<q; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nThe resultant matrix after addition:\n");

    for (i=0; i<m; i++) {
        for (j=0; j<q; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    // Subtraction of matrices A and B
    printf("\nPerforming matrix subtraction...\n");

    for (i=0; i<m; i++) {
        for (j=0; j<q; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("\nThe resultant matrix after subtraction:\n");

    for (i=0; i<m; i++) {
        for (j=0; j<q; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    // Multiplication of matrices A and B
    printf("\nPerforming matrix multiplication...\n");

    for (i=0; i<m; i++) {
        for (j=0; j<q; j++) {
            c[i][j] = 0;
            for (k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nThe resultant matrix after multiplication:\n");

    for (i=0; i<m; i++) {
        for (j=0; j<q; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for trusting me to guide you through this Matrix operations program, I hope you found it helpful!\n");

    return 0;
}