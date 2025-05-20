//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>

int main(void) {
  int row, col, i, j;
  int arr1[100][100], arr2[100][100], result[100][100];

  printf("Enter the number of rows and columns of matrix: ");
  scanf("%d %d", &row, &col);

  // Get the elements of first matrix
  printf("\nEnter the elements of first matrix:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      scanf("%d", &arr1[i][j]);
    }
  }

  // Get the elements of second matrix
  printf("\nEnter the elements of second matrix:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      scanf("%d", &arr2[i][j]);
    }
  }

  // Add the matrices
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      result[i][j] = arr1[i][j] + arr2[i][j];
    }
  }

  // Display the result
  printf("\nSum of matrices:\n");
  for(i=0; i<row; i++) {
    for(j=0; j<col; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  // Find the transpose of the result matrix
  printf("\nTranspose of the result matrix:\n");
  for(i=0; i<col; i++) {
    for(j=0; j<row; j++) {
      printf("%d\t", result[j][i]);
    }
    printf("\n");
  }

  // Find the product of the matrices
  if(row == col) {
    int mul[100][100];
    int k, sum;

    for(i=0; i<row; i++) {
      for(j=0; j<col; j++) {
        sum = 0;
        for(k=0; k<row; k++) {
          sum += arr1[i][k] * arr2[k][j];
        }
        mul[i][j] = sum;
      }
    }

    printf("\nProduct of matrices:\n");
    for(i=0; i<row; i++) {
      for(j=0; j<col; j++) {
        printf("%d\t", mul[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("\nMatrix multiplication is not possible as the number of rows and columns are not equal\n");
  }

  return 0;
}