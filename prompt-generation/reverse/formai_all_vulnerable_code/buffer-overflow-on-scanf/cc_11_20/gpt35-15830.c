//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

int main() {
  //Welcome Message
  printf("Welcome to the Matrix operations program!\n");
  
  //Matrix Declarations
  int m1[50][50], m2[50][50], res[50][50];
  int row1, col1, row2, col2, i, j, k;
  
  //Get user input for matrix sizes
  printf("Enter number of rows for the first matrix: ");
  scanf("%d",&row1);
  
  printf("Enter number of columns for the first matrix: ");
  scanf("%d",&col1);
  
  printf("Enter number of rows for the second matrix: ");
  scanf("%d",&row2);
  
  printf("Enter number of columns for the second matrix: ");
  scanf("%d",&col2);
  
  //Check if matrices can be multiplied
  if (col1 != row2) {
    printf("Matrices cannot be multiplied! Please try again.\n");
    return 0;
  }
  
  //Get user input for matrix values
  printf("Enter elements in first matrix:\n");
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col1; j++) {
      scanf("%d", &m1[i][j]);
    }
  }
  
  printf("Enter elements in second matrix:\n");
  for (i = 0; i < row2; i++) {
    for (j = 0; j < col2; j++) {
      scanf("%d", &m2[i][j]);
    }
  }
  
  //Perform matrix multiplication
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      res[i][j] = 0;
      for (k = 0; k < col1; k++) {
        res[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  
  //Print result matrix
  printf("Resultant matrix:\n");
  for (i = 0; i < row1; i++) {
    for (j = 0; j < col2; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  
  //Goodbye Message
  printf("Matrix operations program completed successfully!\n");
  
  return 0;
}