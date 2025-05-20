//FormAI DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include<stdio.h>

int main()
{
  int a[3][3], b[3][3], c[3][3], i, j, k;

  printf("Enter the elements of matrix A:\n");

  //input matrix A
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
          scanf("%d",&a[i][j]);
      }
  }

  printf("Enter the elements of matrix B:\n");

  //input matrix B
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
          scanf("%d",&b[i][j]);
      }
  }

  //performing matrix multiplication 
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
          c[i][j]=0;
          for(k=0;k<3;k++)
          {
              c[i][j]= c[i][j] + a[i][k] * b[k][j];
          }
      }
  }

  printf("Resultant matrix C:\n");

  //displaying the resultant matrix
  for(i=0;i<3;i++)
  {
      for(j=0;j<3;j++)
      {
          printf("%d\t",c[i][j]);
      }
      printf("\n");
  }

  return 0;
}