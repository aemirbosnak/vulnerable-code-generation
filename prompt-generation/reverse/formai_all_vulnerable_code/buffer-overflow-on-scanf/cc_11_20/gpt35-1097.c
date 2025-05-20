//FormAI DATASET v1.0 Category: Matrix operations ; Style: complete
#include<stdio.h>

int main(){
    int row1, col1, row2, col2;

    //Taking input for first matrix
    printf("Enter dimensions for first matrix (row column): \n");
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];

    printf("Enter elements for first matrix: \n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    //Taking input for second matrix
    printf("Enter dimensions for second matrix (row column): \n");
    scanf("%d %d", &row2, &col2);

    int matrix2[row2][col2];

    printf("Enter elements for second matrix: \n");
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    //Checking if matrix multiplication is valid
    if(col1 != row2){
        printf("Invalid matrix dimensions for multiplication! Exiting program.");
        return 0;
    }

    //Performing matrix addition and printing result
    printf("\nResult of matrix addition:\n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            printf("%d ", matrix1[i][j]+matrix2[i][j]);
        }
        printf("\n");
    }

    //Performing matrix multiplication and printing result
    printf("\nResult of matrix multiplication:\n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            int product = 0;
            for(int k=0; k<row2; k++){
                product += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", product);
        }
        printf("\n");
    }

    return 0;
}