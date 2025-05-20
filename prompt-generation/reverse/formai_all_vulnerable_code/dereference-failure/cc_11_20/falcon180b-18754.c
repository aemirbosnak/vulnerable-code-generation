//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k;
    int **matrix1, **matrix2, **result;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d%d", &rows, &cols);
    matrix1 = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Enter the elements of the first matrix:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d%d", &rows, &cols);
    matrix2 = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Enter the elements of the second matrix:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    result = (int **)malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The sum of the two matrices is:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    free(matrix1);
    free(matrix2);
    free(result);
    return 0;
}