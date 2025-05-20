//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() //Function for displaying menu.
{
  printf("MATRIX OPERATIONS\n");
  printf("------------------------\n");
  printf("1. Add two matrices\n");
  printf("2. Subtract two matrices\n");
  printf("3. Multiply two matrices\n");
  printf("4. Transpose of a matrix\n");
  printf("5. Exit\n");
  printf("------------------------\n");
  printf("Enter your choice: ");
}

void addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols]) //Function for adding two matrices.
{
  int result[rows][cols];
  printf("Enter elements of matrix 1:\n");
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      scanf("%d",&matrix1[i][j]);
    }
  }
  printf("Enter elements of matrix 2:\n");
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      scanf("%d",&matrix2[i][j]);
    }
  }
  printf("Resultant matrix after addition:\n");
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      result[i][j] = matrix1[i][j] + matrix2[i][j];
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }
}

void subtractMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols]) //Function for subtracting two matrices.
{
  int result[rows][cols];
  printf("Enter elements of matrix 1:\n");
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      scanf("%d",&matrix1[i][j]);
    }
  }
  printf("Enter elements of matrix 2:\n");
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      scanf("%d",&matrix2[i][j]);
    }
  }
  printf("Resultant matrix after subtraction:\n");
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      result[i][j] = matrix1[i][j] - matrix2[i][j];
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }
}

void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2]) //Function for multiplying two matrices.
{
  int result[rows1][cols2];
  printf("Enter elements of matrix 1:\n");
  for(int i=0;i<rows1;i++){
    for(int j=0;j<cols1;j++){
      scanf("%d",&matrix1[i][j]);
    }
  }
  printf("Enter elements of matrix 2:\n");
  for(int i=0;i<rows2;i++){
    for(int j=0;j<cols2;j++){
      scanf("%d",&matrix2[i][j]);
    }
  }
  if(cols1!=rows2){
    printf("Matrix multiplication not possible.\n");
    return;
  }
  for(int i=0;i<rows1;i++){
    for(int j=0;j<cols2;j++){
      int sum = 0;
      for(int k=0;k<cols1;k++){
        sum += matrix1[i][k] * matrix2[k][j];
      }
      result[i][j] = sum;
      printf("%d ",result[i][j]);
    }
    printf("\n");
  }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols]) //Function for finding transpose of a matrix.
{
  for(int i=0;i<cols;i++){
    for(int j=0;j<rows;j++){
      printf("%d ",matrix[j][i]);
    }
    printf("\n");
  }

}

int main()
{
  int rows1, cols1, rows2, cols2;
  printf("Enter dimensions of matrix 1: ");
  scanf("%d%d",&rows1,&cols1);
  printf("Enter dimensions of matrix 2: ");
  scanf("%d%d",&rows2,&cols2);
  int matrix1[rows1][cols1], matrix2[rows2][cols2];
  while(1){
    displayMenu();
    int choice;
    scanf("%d",&choice);
    switch(choice){
      case 1:
        addMatrix(rows1, cols1, matrix1, matrix2);
        break;
      case 2:
        subtractMatrix(rows1, cols1, matrix1, matrix2);
        break;
      case 3:
        multiplyMatrix(rows1, cols1, matrix1, rows2, cols2, matrix2);
        break;
      case 4:
        printf("Enter elements of the matrix:\n");
        for(int i=0;i<rows1;i++){
          for(int j=0;j<cols1;j++){
            scanf("%d",&matrix1[i][j]);
          }
        }
        printf("Transpose of the matrix:\n");
        transposeMatrix(rows1, cols1, matrix1);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice, please try again.\n");
    }
  }
  return 0;
}