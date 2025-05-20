//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

    int a[3][3], b[3][3], c[3][3];
    int i, j;

    printf("Welcome to the happy C Matrix operations example program!\n");
    printf("In this program, we will add, subtract and multiply matrices with joy!\n");

    // Taking input for matrix A
    printf("\nEnter elements of matrix A:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    // Taking input for matrix B
    printf("\nEnter elements of matrix B:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    // Adding matrices A and B
    printf("\nAdding matrices A and B with happiness:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Subtracting matrix B from matrix A
    printf("\nSubtracting matrix B from matrix A with joy:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            c[i][j] = a[i][j] - b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Multiplying matrices A and B
    printf("\nMultiplying matrices A and B with excitement:\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            c[i][j] = 0;
            for(int k=0; k<3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("\nHooray! All operations have been completed with happiness, joy and excitement!\n");

    return 0;
}