//FormAI DATASET v1.0 Category: Matrix operations ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int **mat,int rows,int cols);        //function to display the matrix
int getRand(int min,int max);                     //function to generate random numbers

int main()
{
    srand(time(0));                              //seeding the random number generator
    printf("Enter number of rows of the matrix: ");
    int rows;
    scanf("%d",&rows);                            //taking input for rows of the matrix
    printf("Enter number of columns of the matrix: ");
    int cols;
    scanf("%d",&cols);                            //taking input for columns of the matrix

    int **mat1,**mat2,**mat3;                      //declaring 3 matrix of size rows x cols

    mat1=(int**)malloc(rows*sizeof(int*));         //dynamically allocating memory for matrix1
    mat2=(int**)malloc(rows*sizeof(int*));         //dynamically allocating memory for matrix2
    mat3=(int**)malloc(rows*sizeof(int*));         //dynamically allocating memory for matrix3

    for(int i=0;i<rows;i++)
    {
        mat1[i]=(int*)malloc(cols*sizeof(int));    //dynamically allocating memory for matrix1 rows
        mat2[i]=(int*)malloc(cols*sizeof(int));    //dynamically allocating memory for matrix2 rows    
        mat3[i]=(int*)malloc(cols*sizeof(int));    //dynamically allocating memory for matrix3 rows

        for(int j=0;j<cols;j++)
        {
            mat1[i][j]=getRand(1,10);              //filling matrix1 with random numbers between 1 to 10
            mat2[i][j]=getRand(1,10);              //filling matrix2 with random numbers between 1 to 10
            mat3[i][j]=0;                          //initializing matrix3 with zeroes
        }
    }

    printf("\nMatrix 1:\n");
    display(mat1,rows,cols);                      //displaying matrix1
    printf("\nMatrix 2:\n");
    display(mat2,rows,cols);                      //displaying matrix2

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            for(int k=0;k<cols;k++)
            {
                mat3[i][j]+=mat1[i][k]*mat2[k][j]; //multiplying matrices1 and 2 and storing the result in matrix3
            }
        }
    }

    printf("\nMatrix 1 x Matrix 2:\n");
    display(mat3,rows,cols);                      //displaying the multiplication result matrix3

    for(int i=0;i<rows;i++)
    {
        free(mat1[i]);                            //deallocating memory for matrix1 rows
        free(mat2[i]);                            //deallocating memory for matrix2 rows
        free(mat3[i]);                            //deallocating memory for matrix3 rows
    }

    free(mat1);                                   //deallocating memory for matrix1
    free(mat2);                                   //deallocating memory for matrix2
    free(mat3);                                   //deallocating memory for matrix3

    return 0;
}

void display(int **mat,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d\t",mat[i][j]);             //displaying the elements of the matrix
        }
        printf("\n");
    }
}

int getRand(int min,int max)
{
    return (rand()%(max-min+1))+min;              //generating random number between min and max
}