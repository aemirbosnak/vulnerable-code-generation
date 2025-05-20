//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {

  int i, j, k, rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  int **arr1, **arr2, **arr3;
  arr1 = (int **)malloc(rows * sizeof(int *));
  arr2 = (int **)malloc(rows * sizeof(int *));
  arr3 = (int **)malloc(rows * sizeof(int *));
  
  //allocating memory for the arrays
  for(i=0; i<rows; i++) {
    arr1[i] = (int *)malloc(cols * sizeof(int));
    arr2[i] = (int *)malloc(cols * sizeof(int));
    arr3[i] = (int *)malloc(cols * sizeof(int));
  }

  //getting elements of Array 1
  printf("\nEnter elements of Array 1:\n\n");
  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      printf("Enter element a%d%d: ", i+1, j+1);
      scanf("%d", &arr1[i][j]);
    }
  }

  //getting elements of Array 2
  printf("\nEnter elements of Array 2:\n\n");
  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      printf("Enter element b%d%d: ", i+1, j+1);
      scanf("%d", &arr2[i][j]);
    }
  }

  //Adding two matrices
  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      arr3[i][j] = arr1[i][j] + arr2[i][j];
    }
  }

  //Printing the resultant matrix
  printf("\nResultant Matrix:\n\n");
  for(i=0; i<rows; i++){
    for(j=0; j<cols; j++){
      printf("%d ", arr3[i][j]);
    }
    printf("\n");
  }

  //Deallocating dynamic memory allocation
  for(i=0; i<rows; i++) {
    free(arr1[i]);
    free(arr2[i]);
    free(arr3[i]);
  }
  free(arr1);
  free(arr2);
  free(arr3);

  return 0;
}