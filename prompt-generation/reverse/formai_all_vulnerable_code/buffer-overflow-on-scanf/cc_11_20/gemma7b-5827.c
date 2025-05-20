//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main() {
  int n, m, i, j, k, l, **a, **b, **c;
  n = m = 0;
  a = NULL;
  b = NULL;
  c = NULL;

  srand(time(NULL));

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  printf("Enter the number of columns: ");
  scanf("%d", &m);

  a = (int *)malloc(n * m * sizeof(int));
  b = (int *)malloc(n * m * sizeof(int));
  c = (int *)malloc(n * m * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      a[i * m + j] = rand() % MAX;
      b[i * m + j] = a[i * m + j] > 0 ? 1 : 0;
      c[i * m + j] = 0;
    }
  }

  for (k = 0; k < MAX; k++) {
    for (l = 0; l < n * m; l++) {
      if (b[l] == 1 && c[l] == 0) {
        c[l] = 1;
        for (i = l - m; i >= 0 && c[i] == 0; i--) {
          c[i] = 1;
        }
      }
    }
  }

  printf("The percolated image:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", c[i * m + j]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  free(c);

  return 0;
}