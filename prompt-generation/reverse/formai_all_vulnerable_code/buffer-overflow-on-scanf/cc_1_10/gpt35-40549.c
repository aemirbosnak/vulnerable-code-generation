//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include<stdio.h>

void add(int rows, int columns, int matrix1[10][10], int matrix2[10][10], int result[10][10]){
    for(int i=0;i<rows;i++){ //creating loop for row
        for(int j=0;j<columns;j++){ //creating loop for column
            result[i][j]=matrix1[i][j]+matrix2[i][j]; //calculating sum of matices
        }
    }
}

void subtract(int rows, int columns, int matrix1[10][10], int matrix2[10][10], int result[10][10]){
    for(int i=0;i<rows;i++){ //creating loop for row
        for(int j=0;j<columns;j++){ //creating loop for column
            result[i][j]=matrix1[i][j]-matrix2[i][j]; //calculating difference of matices
        }
    }
}

void multiply(int rows1, int columns1, int rows2, int columns2, int matrix1[10][10], int matrix2[10][10], int result[10][10]){
    for(int i=0;i<rows1;i++){ //creating loop for row of 1st matrix
        for(int j=0;j<columns2;j++){ //creating loop for column of 2nd matrix
            result[i][j]=0; //initializing the elements of resultant matrix as 0
            for(int k=0;k<columns1;k++){ //creating loop for column of 1st matrix
                result[i][j]+=matrix1[i][k]*matrix2[k][j]; //calculating product of matrices
            }
        }
    }
}

int main(){
    int matrix1[10][10], matrix2[10][10], result[10][10], rows1, rows2, columns1, columns2;

    printf("Enter the number of rows and columns of the 1st matrix: ");
    scanf("%d %d", &rows1, &columns1);

    printf("Enter the elements of the 1st matrix: \n");
    for(int i=0;i<rows1;i++){ //creating loop for row
        for(int j=0;j<columns1;j++){ //creating loop for column
            scanf("%d", &matrix1[i][j]); //accepting elements of matrices
        }
    }

    printf("Enter the number of rows and columns of the 2nd matrix: ");
    scanf("%d %d", &rows2, &columns2);

    printf("Enter the elements of the 2nd matrix: \n");
    for(int i=0;i<rows2;i++){ //creating loop for row
        for(int j=0;j<columns2;j++){ //creating loop for column
            scanf("%d", &matrix2[i][j]); //accepting elements of matrices
        }
    }

    printf("The sum of the matrices is: \n");
    if(rows1==rows2 && columns1==columns2){
        add(rows1, columns1, matrix1, matrix2, result); //calling function for addition of matrices
        for(int i=0;i<rows1;i++){ //creating loop for row
            for(int j=0;j<columns1;j++){ //creating loop for column
                printf("%d ", result[i][j]); //printing result matrix
            }
            printf("\n");
        }
    }
    else{
        printf("Matrices cannot be added as they have different dimensions!\n");
    }

    printf("The difference of the matrices is: \n");
    if(rows1==rows2 && columns1==columns2){
        subtract(rows1, columns1, matrix1, matrix2, result); //calling function for subtraction of matrices
        for(int i=0;i<rows1;i++){ //creating loop for row
            for(int j=0;j<columns1;j++){ //creating loop for column
                printf("%d ", result[i][j]); //printing result matrix
            }
            printf("\n");
        }
    }
    else{
        printf("Matrices cannot be subtracted as they have different dimensions!\n");
    }

    printf("The product of the matrices is: \n");
    if(columns1==rows2){
        multiply(rows1, columns1, rows2, columns2, matrix1, matrix2, result); //calling function for multiplication of matrices
        for(int i=0;i<rows1;i++){ //creating loop for row
            for(int j=0;j<columns2;j++){ //creating loop for column
                printf("%d ", result[i][j]); //printing result matrix
            }
            printf("\n");
        }
    }
    else{
        printf("Matrices cannot be multiplied as their dimensions are incompatible!\n");
    }
    return 0;
}