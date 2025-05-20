//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

int main() {
  
  printf("Hello there, let's do some happy matrix operations!\n");
  
  int m, n, i, j, a[10][10], b[10][10], sum[10][10], mul[10][10];
  
  printf("Enter the dimensions of the matrices:\n");
  scanf("%d %d", &m, &n);
  
  printf("Enter the elements of the first matrix:\n");
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  printf("Enter the elements of the second matrix:\n");
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  
  //adding matrices
  printf("\n\nLet's add the matrices:\n\n");
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      sum[i][j] = a[i][j] + b[i][j];
      printf("%d ", sum[i][j]);
    }
    printf("\n");
  }
  
  //multiplying matrices
  printf("\n\nLet's multiply the matrices:\n\n");
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      mul[i][j] = 0;
      for (int k = 0; k < n; k++) {
        mul[i][j] += a[i][k] * b[k][j];
      }
      printf("%d ", mul[i][j]);
    }
    printf("\n");
  }
  
  printf("\n\nYay, we did it! Have a happy day ahead! :)\n");
  
  return 0;
}