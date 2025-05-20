//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include<stdio.h>

//function to add two matrices
void matrix_addition(int x[][10], int y[][10], int result[][10], int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            result[i][j] = x[i][j] + y[i][j];
        }
    }
}

//function to multiply two matrices
void matrix_multiplication(int x[][10], int y[][10], int result[][10], int rows, int columns, int columns2){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns2; j++){
            result[i][j] = 0;
            for(int k=0; k<columns; k++){
                result[i][j] += x[i][k] * y[k][j];
            }
        }
    }
}

//function to display the matrix
void display_matrix(int x[][10], int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}

int main(){

    int rows, columns, columns2;

    //ask user for input
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &columns);

    int matrix1[rows][columns];

    //ask user to input matrix 1
    printf("Enter elements for matrix 1:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    //display matrix 1
    printf("\nMatrix 1:\n");
    display_matrix(matrix1, rows, columns);

    //ask user for input
    printf("\nEnter number of rows for matrix 2: ");
    scanf("%d", &rows);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &columns2);

    int matrix2[rows][columns2];

    //ask user to input matrix 2
    printf("Enter elements for matrix 2:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    //display matrix 2
    printf("\nMatrix 2:\n");
    display_matrix(matrix2, rows, columns2);

    //addition of two matrices
    int result_addition[rows][columns2];
    matrix_addition(matrix1, matrix2, result_addition, rows, columns2);

    //display addition of two matrices
    printf("\nAddition of Matrix 1 and Matrix 2 is:\n");
    display_matrix(result_addition, rows, columns2);

    //multiply two matrices
    if(columns == rows){
        int result_multiplication[rows][columns2];
        matrix_multiplication(matrix1, matrix2, result_multiplication, rows, columns, columns2);

        //display multiplication of two matrices
        printf("\nMultiplication of Matrix 1 and Matrix 2 is:\n");
        display_matrix(result_multiplication, rows, columns2);
    }
    else{
        printf("\nMatrices cannot be multiplied as number of columns in first matrix is not equal to number of rows in the second matrix.\n");
    }

    return 0;
}