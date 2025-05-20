//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main() {
  int n, m, i, j, k, p, q;
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  printf("Enter the number of columns: ");
  scanf("%d", &m);
  printf("Enter the number of iterations: ");
  scanf("%d", &k);

  int **arr = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    arr[i] = (int *)malloc(m * sizeof(int));
  }

  srand(time(NULL));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      arr[i][j] = rand() % 2;
    }
  }

  for (p = 0; p < k; p++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (arr[i][j] == 1) {
          q = rand() % 4;
          switch (q) {
            case 0:
              arr[i - 1][j] = 1;
              break;
            case 1:
              arr[i + 1][j] = 1;
              break;
            case 2:
              arr[i][j - 1] = 1;
              break;
            case 3:
              arr[i][j + 1] = 1;
              break;
          }
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);
  return 0;
}