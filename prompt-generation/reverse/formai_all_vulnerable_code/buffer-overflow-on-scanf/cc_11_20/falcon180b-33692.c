//Falcon-180B DATASET v1.0 Category: Educational ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int n, i, j, k, l, m, count = 0;
  int matrix1[10][10], matrix2[10][10], add[10][10], multiply[10][10];
  char ch;

  printf("Enter the number of rows and columns of the first matrix: ");
  scanf("%d%d", &n, &m);

  printf("Enter the elements of the first matrix:\n");
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("Enter the number of rows and columns of the second matrix: ");
  scanf("%d%d", &l, k);

  if(m!= l)
  {
    printf("The matrices cannot be added or multiplied.\n");
    exit(0);
  }

  printf("Enter the elements of the second matrix:\n");
  for(i = 0; i < l; i++)
  {
    for(j = 0; j < k; j++)
    {
      scanf("%d", &matrix2[i][j]);
    }
  }

  printf("Enter 'A' to add the matrices and 'M' to multiply the matrices: ");
  scanf(" %c", &ch);

  switch(ch)
  {
    case 'A':
      for(i = 0; i < n; i++)
      {
        for(j = 0; j < m; j++)
        {
          add[i][j] = matrix1[i][j] + matrix2[i][j];
        }
      }

      printf("The sum of the matrices is:\n");
      for(i = 0; i < n; i++)
      {
        for(j = 0; j < m; j++)
        {
          printf("%d\t", add[i][j]);
        }
        printf("\n");
      }

      break;

    case 'M':
      for(i = 0; i < n; i++)
      {
        for(j = 0; j < k; j++)
        {
          for(l = 0; l < m; l++)
          {
            multiply[i][j] += matrix1[i][l] * matrix2[l][j];
          }
        }
      }

      printf("The product of the matrices is:\n");
      for(i = 0; i < n; i++)
      {
        for(j = 0; j < k; j++)
        {
          printf("%d\t", multiply[i][j]);
        }
        printf("\n");
      }

      break;

    default:
      printf("Invalid choice.\n");
  }

  return 0;
}