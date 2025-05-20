//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, rows, columns;
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &columns);

    int **matrix = (int **) malloc(rows * sizeof(int *));
    for(i=0; i<rows; i++){
        matrix[i] = (int *) malloc(columns * sizeof(int));
    }

    int **transpose = (int **) malloc(columns * sizeof(int *));
    for(i=0; i<columns; i++){
        transpose[i] = (int *) malloc(rows * sizeof(int));
    }

    printf("\nEnter the elements of the matrix:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    //Printing the original matrix
    printf("\nOriginal Matrix:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    //Finding the transpose of the matrix
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    //Printing the transpose of the matrix
    printf("\nTranspose of the matrix:\n");
    for(i=0; i<columns; i++){
        for(j=0; j<rows; j++){
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }

    //Finding the sum of the elements of the matrix
    int sum = 0;
    for(i=0; i<rows; i++){
        for(j=0; j<columns; j++){
            sum += matrix[i][j];
        }
    }
    printf("\nSum of all the elements of the matrix is: %d\n",sum);

    //Finding the product of the diagonal elements of the matrix
    int product = 1;
    int min = (rows < columns) ? rows : columns; //Finding the minimum of rows and columns
    for(i=0; i<min; i++){
        product *= matrix[i][i];
    }
    printf("\nProduct of the diagonal elements of the matrix is: %d\n",product);

    //Freeing the dynamically allocated memory
    for(i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);

    for(i=0; i<columns; i++){
        free(transpose[i]);
    }
    free(transpose);

    return 0;
}