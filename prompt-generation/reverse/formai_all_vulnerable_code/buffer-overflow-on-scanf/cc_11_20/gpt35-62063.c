//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

int main(){
  int row1, col1, row2, col2, i, j, k;
  int **mat1, **mat2, **mat3;
  
  printf("Enter the number of rows in matrix 1: ");
  scanf("%d", &row1);
  printf("Enter the number of columns in matrix 1: ");
  scanf("%d", &col1);
  mat1 = (int **)malloc(row1 * sizeof(int *));
  for(i=0; i<row1; i++){
    mat1[i] = (int *)malloc(col1 * sizeof(int));
  }
  printf("Enter the elements of matrix 1:\n");
  for(i=0; i<row1; i++){
    for(j=0; j<col1; j++){
      scanf("%d", &mat1[i][j]);
    }
  }
  
  printf("Enter the number of rows in matrix 2: ");
  scanf("%d", &row2);
  printf("Enter the number of columns in matrix 2: ");
  scanf("%d", &col2);
  
  if(col1 != row2){
    printf("Matrix multiplication is not possible!\n");
    return 0;
  }
  
  mat2 = (int **)malloc(row2 * sizeof(int *));
  for(i=0; i<row2; i++){
    mat2[i] = (int *)malloc(col2 * sizeof(int));
  }
  printf("Enter the elements of matrix 2:\n");
  for(i=0; i<row2; i++){
    for(j=0; j<col2; j++){
      scanf("%d", &mat2[i][j]);
    }
  }
  
  mat3 = (int **)malloc(row1 * sizeof(int *));
  for(i=0; i<row1; i++){
    mat3[i] = (int *)malloc(col2 * sizeof(int));
  }
  
  for(i=0; i<row1; i++){
    for(j=0; j<col2; j++){
      mat3[i][j] = 0;
      for(k=0; k<col1; k++){
        mat3[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  
  printf("The result of matrix multiplication is:\n");
  for(i=0; i<row1; i++){
    for(j=0; j<col2; j++){
      printf("%d ", mat3[i][j]);
    }
    printf("\n");
  }
  
  for(i=0; i<row1; i++){
    free(mat1[i]);
    free(mat3[i]);
  }
  for(i=0; i<row2; i++){
    free(mat2[i]);
  }
  free(mat1);
  free(mat2);
  free(mat3);
  
  return 0;
}