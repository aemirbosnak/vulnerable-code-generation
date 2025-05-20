//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>

/*
 * This program performs matrix operations on a user-defined matrix.
 * The user chooses the size of the matrix and the elements of the matrix.
 * The program then allows the user to choose between addition, subtraction, and multiplication of matrices.
 */

int main(){

    int row, col, choice;

    printf("Enter the number of rows for your matrix: ");
    scanf("%d", &row);
    printf("Enter the number of columns for your matrix: ");
    scanf("%d", &col);

    int matrix1[row][col], matrix2[row][col];

    // Populating the matrices
    printf("Enter the elements of your first matrix:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of your second matrix:\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Menu for selecting matrix operations
    printf("What operation do you want to perform?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);

    if(choice == 1){
        // Matrix addition
        int sumMatrix[row][col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        printf("The sum of the matrices is:\n");
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                printf("%d ", sumMatrix[i][j]);
            }
            printf("\n");
        }

    } else if(choice == 2){
        // Matrix subtraction
        int differenceMatrix[row][col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                differenceMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }

        printf("The difference of the matrices is:\n");
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                printf("%d ", differenceMatrix[i][j]);
            }
            printf("\n");
        }   

    } else if(choice == 3){
        // Matrix multiplication
        int resultMatrix[row][col];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                resultMatrix[i][j] = 0;
                for(int k = 0; k < col; k++){
                    resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        printf("The result of the matrix multiplication is:\n");
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                printf("%d ", resultMatrix[i][j]);
            }
            printf("\n");
        }   

    } else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}