//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h> // Standard I/O library
#include <stdlib.h> // Standard library

int main() {
    printf("Hello there! Let's have fun with matrices!\n");

    int rows, cols; // Declare the variables to store the number of rows and columns

    printf("Enter the number of rows: ");
    scanf("%d", &rows); // Read the number of rows

    printf("Enter the number of columns: ");
    scanf("%d", &cols); // Read the number of columns

    int matrix[rows][cols]; // Declare the matrix with the given size

    printf("\nEnter the elements of the matrix:\n");
    // Loop through the rows and columns to read the elements
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Your matrix is:\n");
    // Loop through the rows and columns to print the elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nLet's perform some operations on the matrix:\n");

    // Declare a variable to store the sum of all elements
    int sum = 0;
    // Loop through the rows and columns to calculate the sum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    printf("\nThe sum of all elements is %d\n", sum);

    // Declare a variable to store the product of the diagonal elements
    int product = 1;
    // Loop through the rows and columns to calculate the product
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) { // Check if the element is on the diagonal
                product *= matrix[i][j];
            }
        }
    }
    printf("\nThe product of the diagonal elements is %d\n", product);

    // Declare a variable to store the maximum element in the matrix
    int max = matrix[0][0];
    // Loop through the rows and columns to find the maximum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    printf("\nThe maximum element in the matrix is %d\n", max);

    // Declare a variable to store the minimum element in the matrix
    int min = matrix[0][0];
    // Loop through the rows and columns to find the minimum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    printf("\nThe minimum element in the matrix is %d\n", min);

    printf("\nThanks for playing with matrices!\n");

    return 0;
}