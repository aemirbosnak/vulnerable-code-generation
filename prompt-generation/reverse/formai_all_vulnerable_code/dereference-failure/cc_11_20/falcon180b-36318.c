//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //initialize random seed
    srand(time(NULL));

    //define matrix dimensions
    int rows = rand() % 10 + 2;
    int cols = rand() % 10 + 2;

    //allocate memory for matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    //populate matrix with random numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    //print matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    //transpose matrix
    int **transpose_matrix = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transpose_matrix[i] = (int *)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose_matrix[j][i] = matrix[i][j];
        }
    }

    //print transpose
    printf("Transpose Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }

    //free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < cols; i++) {
        free(transpose_matrix[i]);
    }
    free(transpose_matrix);

    return 0;
}