//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
    printf("Wooohooo! Time for some matrix operations!!\n");

    int A[3][3], B[3][3], sum[3][3], transpose[3][3];

    printf("Please enter the first matrix, A:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Enter element [%d][%d] of A: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nNow, let's enter the second matrix, B:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Enter element [%d][%d] of B: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nWooohooo! The matrices have been inputted perfectly, now it's time to perform some operations!\n");

    // Add Matrices A and B
    printf("\n\n\t\t\tADDING MATRICES A AND B:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nThe sum of matrices A and B is:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    // Transpose of matrix A
    printf("\n\n\t\t\tFINDING TRANSPOSE OF MATRIX A:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            transpose[j][i] = A[i][j];
        }
    }

    printf("\nThe transpose of matrix A is:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    printf("\n\nWooohooo! The matrix operations have been performed successfully, aren't you excited?!");

    return 0;
}