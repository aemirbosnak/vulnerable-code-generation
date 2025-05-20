//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the size of the matrices
  int n;
  printf("Enter the size of the matrices: ");
  scanf("%d", &n);

  // Allocate memory for the matrices
  int **a = (int **)malloc(n * sizeof(int *));
  int **b = (int **)malloc(n * sizeof(int *));
  int **c = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
    b[i] = (int *)malloc(n * sizeof(int));
    c[i] = (int *)malloc(n * sizeof(int));
  }

  // Get the elements of the matrices
  printf("Enter the elements of the first matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of the second matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // Add the two matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  // Print the result
  printf("The sum of the two matrices is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < n; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }

  free(a);
  free(b);
  free(c);

  return 0;
}