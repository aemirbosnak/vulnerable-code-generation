//FormAI DATASET v1.0 Category: Funny ; Style: complex
#include<stdio.h>

int main(){

  int i, j, k;
  int a[5][5], b[5][5], c[5][5];

  printf("Enter the elements of First Matrix:\n");

  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      printf("Enter element a[%d][%d]: ",i,j);
      scanf("%d",&a[i][j]);
    }
    printf("\n");
  }

  printf("\nEnter the elements of Second Matrix:\n");

  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      printf("Enter element b[%d][%d]: ",i,j);
      scanf("%d",&b[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix A:\n");
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      printf("%d ",b[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      c[i][j]=0;
      for(k=0;k<5;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }

  printf("\nMatrix C (Result of Matrix Multiplication):\n");
  for(i=0;i<5;i++){
    for(j=0;j<5;j++){
      printf("%d ",c[i][j]);
    }
    printf("\n");
  }

  return 0;

}