//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ROW 3
#define COL 3
void init(int mat[][COL], int r , int c);
void display(int mat[][COL], int r , int c);
void add(int mat1[][COL], int mat2[][COL], int r , int c);
void subtract(int mat1[][COL], int mat2[][COL], int r , int c);
void multiply(int mat1[][COL], int mat2[][COL], int r , int c);
void transpose(int mat[][COL], int r , int c);
int main()
{
    int mat1[ROW][COL] , mat2[ROW][COL];
    int choice;
    printf("ENTER MATRIX 1\n");
    init(mat1 , ROW , COL);
    printf("ENTER MATRIX 2\n");
    init(mat2 , ROW , COL);
    printf("MATRIX 1      :  \n");
    display(mat1 , ROW , COL);
    printf("MATRIX 2      :  \n");
    display(mat2 , ROW , COL);
    printf("ENTER THE OPERATION CHOICE : \n");
    printf("1 FOR ADDITION \n2 FOR SUBSTRACTION\n3 FOR MULTIPLICATION \n4 FOR TRANSPOSE\n");
    scanf("%d" , &choice);
    switch(choice)
    {
        case 1 : add(mat1 , mat2 , ROW , COL);
                 break;

        case 2 : subtract(mat1 , mat2 , ROW , COL);
                 break;

        case 3 : multiply(mat1 , mat2 , ROW , COL);
                 break;

        case 4 : transpose(mat1 , ROW , COL);
                 break;

        default : printf("INVALID CHOICE");
    }
    return 0;
}
void init(int mat[][COL], int r , int c)
{
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}
void display(int mat[][COL], int r , int c)
{
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}
void add(int mat1[][COL], int mat2[][COL], int r , int c)
{
    int ans[ROW][COL];
    printf("SUM OF MATRIX IS\n");
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            ans[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d\t" , ans[i][j]);
        }
        printf("\n");
    }
}
void subtract(int mat1[][COL], int mat2[][COL], int r , int c)
{
    int ans[ROW][COL];
    printf("DIFFERENCE OF MATRIX IS\n");
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            ans[i][j] = mat1[i][j] - mat2[i][j];
            printf("%d\t" , ans[i][j]);
        }
        printf("\n");
    }
}
void multiply(int mat1[][COL], int mat2[][COL], int r , int c)
{
    int ans[ROW][COL];
    printf("MULTIPLICATION OF MATRIX IS\n");
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            ans[i][j] = 0;
            for(int k = 0 ; k < r ; k++)
            {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
            printf("%d\t" , ans[i][j]);
        }
        printf("\n");
    }
}
void transpose(int mat[][COL], int r , int c)
{
    int ans[ROW][COL];
    printf("TRANSPOSE OF MATRIX IS\n");
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            ans[i][j] = mat[j][i];
            printf("%d\t" , ans[i][j]);
        }
        printf("\n");
    }
}