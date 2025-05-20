//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include<stdio.h>

void fill_matrix(int m[10][10], int row, int col){
   int i,j;

   for (i=0; i<row; i++){
      for (j=0; j<col; j++){
         printf("Enter element m[%d][%d]: ",i,j);
         scanf("%d",&m[i][j]);
      }
   }
}

void print_matrix(int m[10][10], int row, int col){
   int i,j;

   for (i=0; i<row; i++){
      for (j=0; j<col; j++){
         printf("%d\t",m[i][j]);
      }
      printf("\n");
   }
}

void transpose(int m[10][10], int row, int col){
    int i,j,temp;

    for(i=0;i<row;i++){
        for(j=i+1;j<col;j++){
            temp=m[i][j];
            m[i][j]=m[j][i];
            m[j][i]=temp;
        }
    }
}

void add(int mat1[10][10], int mat2[10][10], int res[10][10], int row1, int col1, int row2, int col2){
    int i,j;

    if(row1!=row2 || col1!=col2){
        printf("Error: Cannot add matrices of different dimensions.\n");
        return;
    }

    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            res[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
}

void subtract(int mat1[10][10], int mat2[10][10], int res[10][10], int row1, int col1, int row2, int col2){
    int i,j;

    if(row1!=row2 || col1!=col2){
        printf("Error: Cannot subtract matrices of different dimensions.\n");
        return;
    }

    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            res[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
}

void multiply(int mat1[10][10], int mat2[10][10], int res[10][10], int row1, int col1, int row2, int col2){
    int i,j,k,sum;

    if(col1!=row2){
        printf("Error: Cannot multiply matrices as their dimensions are not compatible.\n");
        return;
    }

    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            sum=0;
            for(k=0;k<col1;k++){
                sum=sum+mat1[i][k]*mat2[k][j];
            }
            res[i][j]=sum;
        }
    }
}

int main(){
   int m1[10][10], m2[10][10], res[10][10];
   int row1, col1, row2, col2, ch;

   printf("Enter the number of rows and columns of matrix 1: ");
   scanf("%d %d",&row1,&col1);

   printf("Enter the elements of matrix 1:\n");
   fill_matrix(m1,row1,col1);

   printf("Enter the number of rows and columns of matrix 2: ");
   scanf("%d %d",&row2,&col2);

   printf("Enter the elements of matrix 2:\n");
   fill_matrix(m2,row2,col2);

   printf("Matrix 1:\n");
   print_matrix(m1,row1,col1);

   printf("Matrix 2:\n");
   print_matrix(m2,row2,col2);

   printf("Choose operation:\n1. Transpose Matrix 1\n2. Transpose Matrix 2\n3. Add Matrices\n4. Subtract Matrices\n5. Multiply Matrices\n");
   scanf("%d",&ch);

   switch(ch){
       case 1:
            transpose(m1,row1,col1);
            printf("Transpose of Matrix 1:\n");
            print_matrix(m1,row1,col1);
            break;
       case 2:
            transpose(m2,row2,col2);
            printf("Transpose of Matrix 2:\n");
            print_matrix(m2,row2,col2);
            break;
       case 3:
            add(m1,m2,res,row1,col1,row2,col2);
            printf("Resultant matrix:\n");
            print_matrix(res,row1,col1);
            break;
       case 4:
            subtract(m1,m2,res,row1,col1,row2,col2);
            printf("Resultant matrix:\n");
            print_matrix(res,row1,col1);
            break;
       case 5:
            multiply(m1,m2,res,row1,col1,row2,col2);
            printf("Resultant matrix:\n");
            print_matrix(res,row1,col2);
            break;
       default:
            printf("Invalid choice.\n");
            break;
   }

   return 0;
}