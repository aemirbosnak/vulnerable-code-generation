//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

//function to display the matrix
void display(int **matrix, int rows, int cols){
    printf("\nThe updated matrix is\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
int** add_matrices(int **matrix1, int **matrix2, int rows, int cols){
    int **result = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        result[i] = (int *)malloc(cols * sizeof(int));
   
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

//function to multiply two matrices
int** multiply_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2){
    if(cols1 != rows2){
        printf("\nCannot perform matrix multiplication");
        return NULL;
    }
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for(int i = 0; i < rows1; i++)
        result[i] = (int *)malloc(cols2 * sizeof(int));

    int sum = 0;
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            for(int k=0; k<cols1; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
            sum = 0;
        }
    }
    return result;
}

int main(){
    int rows, cols, choice;
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &rows);
    printf("\nEnter the number of columns of the matrix: ");
    scanf("%d", &cols);

    //dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    int element;
    printf("\nEnter the elements of the matrix\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Element[%d][%d]: ", i+1, j+1);
            scanf("%d", &element);
            matrix[i][j] = element;
        }
    }

    printf("\nThe entered matrix is\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    do{
        printf("\nChoose the operation to perform:\n");
        printf("\n1. Add two matrices");
        printf("\n2. Multiply two matrices");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                //dynamically allocate memory for the second matrix
                int **matrix2 = (int **)malloc(rows * sizeof(int *));
                for(int i = 0; i < rows; i++)
                    matrix2[i] = (int *)malloc(cols * sizeof(int));

                printf("\nEnter the elements of the second matrix\n");
                for(int i=0; i<rows; i++){
                    for(int j=0; j<cols; j++){
                        printf("Element[%d][%d]: ", i+1, j+1);
                        scanf("%d", &element);
                        matrix2[i][j] = element;
                    }
                }

                int **result = add_matrices(matrix, matrix2, rows, cols);
                display(result, rows, cols);
                free(matrix2);
                free(result);
                break;
            }

            case 2:{
                int rows2, cols2;

                printf("\nEnter the number of rows of the second matrix: ");
                scanf("%d", &rows2);
                printf("\nEnter the number of columns of the second matrix: ");
                scanf("%d", &cols2);

                //dynamically allocate memory for the second matrix
                int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
                for(int i = 0; i < rows2; i++)
                    matrix2[i] = (int *)malloc(cols2 * sizeof(int));

                printf("\nEnter the elements of the second matrix\n");
                for(int i=0; i<rows2; i++){
                    for(int j=0; j<cols2; j++){
                        printf("Element[%d][%d]: ", i+1, j+1);
                        scanf("%d", &element);
                        matrix2[i][j] = element;
                    }
                }

                int **result = multiply_matrices(matrix, rows, cols, matrix2, rows2, cols2);
                if(result != NULL)
                    display(result, rows, cols2);
                free(matrix2);
                free(result);
                break;
            }

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }

    }while(choice != 3);
    //free the dynamically allocated memory for the matrix
    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}