//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    
    //initialize variables
    int rows, cols, i, j, k, n, sum, count;
    int **matrix, **result;
    double start_time, end_time, elapsed_time;
    
    //get user input for matrix dimensions
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);
    
    //initialize matrices
    matrix = (int **)malloc(rows * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }
    
    //initialize matrix with random values
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    
    //initialize result matrix to zero
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = 0;
        }
    }
    
    //start timer
    start_time = clock();
    
    //perform matrix multiplication
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (k = 0; k < cols; k++) {
                sum = 0;
                for (n = 0; n < rows; n++) {
                    sum += matrix[i][n] * matrix[n][k];
                }
                result[i][j] += sum;
            }
        }
    }
    
    //stop timer and calculate elapsed time
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    //print result matrix
    printf("Result:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    //free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);
    
    return 0;
}