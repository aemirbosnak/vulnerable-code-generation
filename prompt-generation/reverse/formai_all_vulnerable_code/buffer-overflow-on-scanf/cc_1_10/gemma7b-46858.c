//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void search(int **arr, int n, int target) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == target) {
        printf("Target found at (%d, %d)\n", i, j);
        return;
      }
    }
  }

  printf("Target not found\n");
  return;
}

int main() {
  int **arr = NULL;
  int n = 0;

  // Get the number of rows and columns
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Get the number of columns
  printf("Enter the number of columns: ");
  scanf("%d", &n);

  // Allocate memory for the array
  arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    arr[i] = (int *)malloc(n * sizeof(int));
  }

  // Fill the array with numbers
  printf("Enter the numbers for the array: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  // Get the target number
  int target;
  printf("Enter the target number: ");
  scanf("%d", &target);

  // Search for the target number
  search(arr, n, target);

  // Free the memory
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}