//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>

int main() {
  int matrix1[10][10], matrix2[10][10], sum[10][10], multiply[10][10];
  int i, j, k, r1, c1, r2, c2;

  // Input size and elements of first matrix
  printf("Enter rows and columns of first matrix: ");
  scanf("%d %d", &r1, &c1);

  printf("Enter elements of first matrix:\n");
  for(i=0; i<r1; i++) {
    for(j=0; j<c1; j++) {
      scanf("%d", &matrix1[i][j]);
    }
  }

  // Input size and elements of second matrix
  printf("Enter rows and columns of second matrix: ");
  scanf("%d %d", &r2, &c2);

  if(c1 != r2) {
    printf("Multiplication not possible!\n");
    return 0;
  }

  printf("Enter elements of second matrix:\n");
  for(i=0; i<r2; i++) {
    for(j=0; j<c2; j++) {
      scanf("%d", &matrix2[i][j]);
    }
  }

  // Matrix addition
  for(i=0; i<r1; i++) {
    for(j=0; j<c1; j++) {
      sum[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  // Matrix multiplication
  for(i=0; i<r1; i++) {
    for(j=0; j<c2; j++) {
      multiply[i][j]=0;
      for(k=0; k<r2; k++) {
        multiply[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Print the results
  printf("\nSum of the matrices:\n");
  for(i=0; i<r1; i++) {
    for(j=0; j<c1; j++) {
      printf("%d ", sum[i][j]);
    }
    printf("\n");
  }

  printf("\nMultiplication of the matrices:\n");
  for(i=0; i<r1; i++) {
    for(j=0; j<c2; j++) {
      printf("%d ", multiply[i][j]);
    }
    printf("\n");
  }

  return 0;
}