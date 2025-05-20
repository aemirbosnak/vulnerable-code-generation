//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main() {
  int **arr = (int**)malloc(DIM * sizeof(int*));
  for (int i = 0; i < DIM; i++) {
    arr[i] = (int*)malloc(DIM * sizeof(int));
  }

  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      arr[i][j] = 0;
    }
  }

  int x = 0, y = 0, r = 0, d = 0;
  printf("Enter the number of iterations: ");
  scanf("%d", &r);

  for (int t = 0; t < r; t++) {
    printf("Enter the coordinates of the drop (x, y): ");
    scanf("%d %d", &x, &y);

    arr[x][y] = 1;

    for (int i = x - 1; i <= x + 1; i++) {
      for (int j = y - 1; j <= y + 1; j++) {
        if (arr[i][j] == 1) {
          arr[i][j] = 2;
        }
      }
    }
  }

  for (int i = 0; i < DIM; i++) {
    for (int j = 0; j < DIM; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < DIM; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}