//FormAI DATASET v1.0 Category: Educational ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Enter the number of rows and columns:\n");
  int rows, cols;
  scanf("%d %d", &rows, &cols);
  int **arr = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    arr[i] = (int *)malloc(cols * sizeof(int));
  }
  int count = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = ++count;
    }
  }
  printf("The original 2D array:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  int **rotated = (int **)malloc(cols * sizeof(int *));
  for (int i = 0; i < cols; i++) {
    rotated[i] = (int *)malloc(rows * sizeof(int));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      rotated[j][rows-i-1] = arr[i][j];
    }
  }
  printf("The rotated 2D array:\n");
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", rotated[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
  for (int i = 0; i < cols; i++) {
    free(rotated[i]);
  }
  free(rotated);
  return 0;
}