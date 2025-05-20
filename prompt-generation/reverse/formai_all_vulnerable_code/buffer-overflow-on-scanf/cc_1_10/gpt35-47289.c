//FormAI DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int row = 3, col = 3; //global variables for matrix dimensions

//function to take input for matrix
void input_matrix(int matrix[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

//function to display matrix
void display_matrix(int matrix[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to find sum of two matrices
void add_matrices(int matrix1[][col], int matrix2[][col], int result_matrix[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//function to find difference of two matrices
void subtract_matrices(int matrix1[][col], int matrix2[][col], int result_matrix[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

//function to find transpose of matrix
void transpose_matrix(int matrix[][col], int result_matrix[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            result_matrix[j][i] = matrix[i][j];
        }
    }
}

//function to find product of two matrices
void multiply_matrices(int matrix1[][col], int matrix2[][col], int result_matrix[][col]) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            result_matrix[i][j] = 0;
            for(int k=0; k<row; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[row][col], matrix2[row][col], result_matrix[row][col];
    int choice;

    //input matrix 1
    printf("Enter Matrix 1:\n");
    input_matrix(matrix1);

    //input matrix 2
    printf("Enter Matrix 2:\n");
    input_matrix(matrix2);

    //display matrix 1
    printf("\nMatrix 1:\n");
    display_matrix(matrix1);

    //display matrix 2
    printf("\nMatrix 2:\n");
    display_matrix(matrix2);

    //menu for matrix operations
    do {
        printf("\nMatrix Operations Menu:\n");
        printf("1. Sum of two matrices\n");
        printf("2. Difference of two matrices\n");
        printf("3. Transpose of a matrix\n");
        printf("4. Product of two matrices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 : //sum of matrices
                add_matrices(matrix1, matrix2, result_matrix);
                printf("\nMatrix Sum:\n");
                display_matrix(result_matrix);
                break;

            case 2 : //difference of matrices
                subtract_matrices(matrix1, matrix2, result_matrix);
                printf("\nMatrix Difference:\n");
                display_matrix(result_matrix);
                break;

            case 3 : //transpose of matrix
                transpose_matrix(matrix1, result_matrix);
                printf("\nMatrix 1 Transpose:\n");
                display_matrix(result_matrix);
                break;

            case 4 : //product of matrices
                multiply_matrices(matrix1, matrix2, result_matrix);
                printf("\nMatrix Product:\n");
                display_matrix(result_matrix);
                break;

            case 5 : //exit program
                printf("\nExiting program\n");
                break;

            default : //invalid choice
                printf("\nInvalid choice, please try again\n");
        }
    } while(choice != 5);

    return 0;
}