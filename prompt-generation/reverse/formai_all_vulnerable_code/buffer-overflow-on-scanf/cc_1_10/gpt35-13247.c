//FormAI DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>

void displayMatrix(int matrix[][10], int rows, int cols) {
    int i, j;
      
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void addMatrix(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    int i, j;
      
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            result[i][j] = matrix1[i][j]+matrix2[i][j];
}

void multiplyMatrix(int matrix1[][10], int matrix2[][10], int result[][10], int rows, int cols) {
    int i, j, k;

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            result[i][j]=0;
            for(k=0; k<cols; k++)
                result[i][j] += matrix1[i][k]*matrix2[k][j];
        }
    }
}

int main() {
    int a[10][10], b[10][10], sum[10][10], multiply[10][10];
    int rows, cols, i, j;
      
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d%d", &rows, &cols);
    
    printf("\nEnter elements of matrix 1:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("Enter element a%d%d: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
      
    printf("\nEnter elements of matrix 2:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("Enter element b%d%d: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }
      
    printf("\nMatrix 1:\n");
    displayMatrix(a, rows, cols);

    printf("\nMatrix 2:\n");
    displayMatrix(b, rows, cols);
      
    addMatrix(a, b, sum, rows, cols);
    printf("\nSum of matrices:\n");
    displayMatrix(sum, rows, cols);

    multiplyMatrix(a, b, multiply, rows, cols);
    printf("\nProduct of matrices:\n");
    displayMatrix(multiply, rows, cols);

    return 0;
}