//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // maximum size of matrix

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2, rows3, cols3, i, j, k;

    // get dimensions of matrix 1
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &cols1);

    // get dimensions of matrix 2
    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &cols2);

    // check if matrices can be multiplied
    if (cols1!= rows2) {
        printf("Error: matrices cannot be multiplied\n");
        return 0;
    }

    // get dimensions of result matrix
    rows3 = rows1;
    cols3 = cols2;

    // initialize matrices with user input
    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // perform matrix multiplication
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // print result matrix
    printf("Result of matrix multiplication:\n");
    for (i = 0; i < rows3; i++) {
        for (j = 0; j < cols3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}