//FormAI DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {

    int rows, columns, i, j;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &columns);

    int **matrix = (int**)malloc(rows * sizeof(int*)); //creating a dynamic matrix
    for(i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }

    printf("\nPlease enter the elements of the matrix: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe matrix you have entered is: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //Finding the transpose of the matrix
    printf("\nThe transpose of this matrix is: \n");
    for(i = 0; i < columns; i++) {
        for(j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    //Performing matrix addition
    int **matrix2 = (int**)malloc(rows * sizeof(int*)); //creating a second dynamic matrix
    for(i = 0; i < rows; i++) {
        matrix2[i] = (int*)malloc(columns * sizeof(int));
    }

    printf("\nPlease enter the elements of the second matrix: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            scanf("%d", &matrix2[i][j]);
            matrix[i][j] += matrix2[i][j]; //adding the elements of both matrices
        }
    }

    printf("\nThe sum of the two matrices is: \n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //Freeing memory
    for(i = 0; i < rows; i++) {
        free(matrix[i]);
        free(matrix2[i]);
    }
    free(matrix);
    free(matrix2);

    return 0;
}