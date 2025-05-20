//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include<stdio.h>
#include<string.h>

int minimum(int num1, int num2, int num3);

int main()
{
  char str1[20], str2[20];
  int rows, cols, i, j, substitution_cost;
  
  printf("Enter the first string: ");
  scanf("%s", str1);
  
  printf("\nEnter the second string: ");
  scanf("%s", str2);
  
  rows = strlen(str1) + 1;
  cols = strlen(str2) + 1;
  
  int matrix[rows][cols];
  
  for(i = 0; i < rows; i++)
  {
    matrix[i][0] = i;
  }
  
  for(j = 0; j < cols; j++)
  {
    matrix[0][j] = j;
  }
  
  for(i = 1; i < rows; i++)
  {
    for(j = 1; j < cols; j++)
    {
      if(str1[i - 1] == str2[j - 1])
      {
        substitution_cost = 0;
      }
      else
      {
        substitution_cost = 1;
      }
      
      matrix[i][j] = minimum(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + substitution_cost);
    }
  }
  
  printf("\nLevenshtein Distance Matrix: \n");
  
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < cols; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  printf("\nLevenshtein Distance: %d\n", matrix[rows - 1][cols - 1]);
  
  return 0;
}

int minimum(int num1, int num2, int num3)
{
  return num1 < num2 ? (num1 < num3 ? num1 : num3) : (num2 < num3 ? num2 : num3);
}