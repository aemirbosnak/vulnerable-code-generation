//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int main(){
    int row, column;
    printf("Enter number of rows: ");
    scanf("%d", &row); //User input for row
    printf("Enter number of columns: ");
    scanf("%d", &column); //User input for column

    int **matrix;  //declaring a pointer to pointer matrix
    matrix=(int **)malloc(row*sizeof(int *)); //dynamically allocating thememory for rows

    //dynamically allocating the memory for columns
    for(int i=0;i<row;i++){
        *(matrix+i)=(int *)malloc(column*sizeof(int));
    }

    printf("\nEnter the elements of the matrix:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d", &(*(*(matrix+i)+j))); //User input of matrix
        }
    }

    printf("\nThe entered matrix is:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%d ", *(*(matrix+i)+j)); //Displaying the entered matrix
        }printf("\n");
    }

    printf("\nMatrix after transposition:\n");
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            printf("%d ", *(*(matrix+j)+i)); //Transposing the matrix and displaying it
        }printf("\n");
    }

    //Multiplying the matrix by 5 and displaying it
    printf("\nMatrix after multiplication with 5:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            *(*(matrix+i)+j)=(*(*(matrix+i)+j))*5;
            printf("%d ", *(*(matrix+i)+j));
        }printf("\n");
    }

    //Freeing the allocated memory
    for(int i=0;i<row;i++){
        free(*(matrix+i));
    }
    free(matrix);
    return 0;
}