//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>

void print_matrix(int r, int c, int matrix[r][c]){
  printf("\nMatrix:\n");
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void multiply_matrices(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
  if(c1!=r2){
    printf("Matrix multiplication not possible\n");
    return;
  }
  int result[r1][c2];
  printf("\nMultiplication Result:\n");
  for(int i=0;i<r1;i++){
    for(int j=0;j<c2;j++){
      result[i][j] = 0;
      for(int k=0;k<c1;k++){
        result[i][j] += m1[i][k] * m2[k][j];
      }
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
}

void add_matrices(int r, int c, int m1[r][c], int m2[r][c]){
  int result[r][c];
  printf("\nAddition Result:\n");
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      result[i][j] = m1[i][j] + m2[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int r1=2, c1=2, m1[r1][c1];
  printf("\nEnter matrix 1 (2x2):\n");
  for(int i=0;i<r1;i++){
    for(int j=0;j<c1;j++){
      scanf("%d", &m1[i][j]);
    }
  }
  print_matrix(r1, c1, m1);
  
  int r2=2, c2=2, m2[r2][c2];
  printf("\nEnter matrix 2 (2x2):\n");
  for(int i=0;i<r2;i++){
    for(int j=0;j<c2;j++){
      scanf("%d", &m2[i][j]);
    }
  }
  print_matrix(r2, c2, m2);
  
  multiply_matrices(r1, c1, m1, r2, c2, m2);
  add_matrices(r1, c1, m1, m2);
  
  return 0;
}