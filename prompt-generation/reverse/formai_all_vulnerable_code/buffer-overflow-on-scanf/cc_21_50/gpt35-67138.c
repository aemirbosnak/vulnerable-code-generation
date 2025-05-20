//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create the matrix
    int matrix[rows][cols];

    // Populating the matrix with values
    printf("Enter the values of the matrix: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Printing the matrix
    printf("\nThe entered matrix is: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Sum of all elements of the matrix
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    printf("\nSum of all elements of the matrix is %d", sum);

    // Transpose of the matrix
    int transpose[cols][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Printing the transpose of the matrix
    printf("\n\nThe transpose of the matrix is: \n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Product of two matrices
    int rows2, cols2;
    printf("\nEnter the number of rows of the second matrix: ");
    scanf("%d", &rows2);

    printf("Enter the number of columns of the second matrix: ");
    scanf("%d", &cols2);

    // Create the second matrix
    int matrix2[rows2][cols2];

    // Populating the second matrix with values
    printf("\nEnter the values of the second matrix: \n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Printing the second matrix
    printf("\nThe entered second matrix is:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    // Checking if multiplication is possible or not
    if (cols != rows2) {
        printf("\nMultiplication not possible.");
        return 0;
    }

    // Multiplying the two matrices
    int product[rows][cols2];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                product[i][j] += matrix[i][k] * matrix2[k][j];
            }
        }
    }

    // Printing the product of the two matrices
    printf("\nProduct of the two matrices is: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}