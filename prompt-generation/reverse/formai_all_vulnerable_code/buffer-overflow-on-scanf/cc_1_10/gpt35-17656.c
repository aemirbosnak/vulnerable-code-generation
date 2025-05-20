//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//Function to input matrix
void inputMatrix(int **matrix, int rows, int columns) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("Enter the element (%d,%d): ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

//Function to display matrix
void displayMatrix(int **matrix, int rows, int columns) {
    printf("The matrix is:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to perform matrix addition
void addMatrix(int **matrix1, int **matrix2, int rows, int columns) {
    int **result = (int **)malloc(rows*sizeof(int *));
    for(int i=0; i<rows; i++) {
        result[i] = (int *)malloc(columns*sizeof(int));
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("The addition of the given matrices is:\n");
    displayMatrix(result,rows,columns);
}

//Function to perform matrix subtraction
void subMatrix(int **matrix1, int **matrix2, int rows, int columns) {
    int **result = (int **)malloc(rows*sizeof(int *));
    for(int i=0; i<rows; i++) {
        result[i] = (int *)malloc(columns*sizeof(int));
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printf("The subtraction of the given matrices is:\n");
    displayMatrix(result,rows,columns);
}

//Function to perform matrix multiplication
void mulMatrix(int **matrix1, int **matrix2, int rows1, int columns1, int rows2, int columns2) {
    if(columns1 != rows2) {
        printf("Matrix multiplication is not possible as number of columns of matrix 1 is not equal to number of rows of matrix 2.");
        exit(0);
    }
    int **result = (int **)malloc(rows1*sizeof(int *));
    for(int i=0; i<rows1; i++) {
        result[i] = (int *)malloc(columns2*sizeof(int));
    }
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<columns2; j++) {
            result[i][j] = 0;
            for(int k=0; k<columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("The multiplication of the given matrices is:\n");
    displayMatrix(result,rows1,columns2);
}

//Main function
int main() {
    int rows1, columns1, rows2, columns2, choice;
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d",&rows1,&columns1);
    int **matrix1 = (int **)malloc(rows1*sizeof(int *));
    for(int i=0; i<rows1; i++) {
        matrix1[i] = (int *)malloc(columns1*sizeof(int));
    }

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d",&rows2,&columns2);
    int **matrix2 = (int **)malloc(rows2*sizeof(int *));
    for(int i=0; i<rows2; i++) {
        matrix2[i] = (int *)malloc(columns2*sizeof(int));
    }

    printf("Enter the elements of matrix 1:\n");
    inputMatrix(matrix1,rows1,columns1);
    displayMatrix(matrix1,rows1,columns1);

    printf("Enter the elements of matrix 2:\n");
    inputMatrix(matrix2,rows2,columns2);
    displayMatrix(matrix2,rows2,columns2);

    printf("What operation do you want to perform?\n 1. Addition\n 2. Subtraction\n 3. Multiplication\nEnter your choice: ");
    scanf("%d",&choice);
    switch(choice) {
        case 1: 
            if(rows1!=rows2 || columns1!=columns2) {
                printf("Matrix addition is not possible as dimensions are not same for both matrices.");
                exit(0);
            }
            addMatrix(matrix1,matrix2,rows1,columns1);
            break;
        case 2:
            if(rows1!=rows2 || columns1!=columns2) {
                printf("Matrix subtraction is not possible as dimensions are not same for both matrices.");
                exit(0);
            }
            subMatrix(matrix1,matrix2,rows1,columns1);
            break;
        case 3:
            mulMatrix(matrix1,matrix2,rows1,columns1,rows2,columns2);
            break;
        default:
            printf("Invalid choice. Please choose the correct option.");
            exit(0);
    }
    return 0;
}