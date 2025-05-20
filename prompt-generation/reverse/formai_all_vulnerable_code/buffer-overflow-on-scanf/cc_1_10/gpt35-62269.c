//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>

// Function to print the matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 3, cols = 3;
    int matrix[rows][cols];
    
    // Populating the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter the element of row %d and column %d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("The entered matrix is:\n");
    printMatrix(rows, cols, matrix);
    
    // Finding the transpose of the matrix
    int transpose[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    printf("The transpose of the matrix is:\n");
    printMatrix(cols, rows, transpose);
    
    // Finding the determinant of the matrix
    int determinant = 0;
    for (int i = 0; i < rows; i++) {
        determinant += (matrix[0][i] * (matrix[1][(i+1)%3] * matrix[2][(i+2)%3] - matrix[1][(i+2)%3] * matrix[2][(i+1)%3]));
    }
    printf("The determinant of the matrix is: %d\n", determinant);
    
    // Finding the inverse of the matrix
    float inverse[rows][cols];
    int a = determinant;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int b = matrix[(j+1)%3][(i+1)%3] * matrix[(j+2)%3][(i+2)%3] - matrix[(j+2)%3][(i+1)%3] * matrix[(j+1)%3][(i+2)%3];
            inverse[i][j] = (float) b / a;
        }
    }
    
    printf("The inverse of the matrix is:\n");
    printMatrix(rows, cols, inverse);
    
    return 0;
}