//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  char *s = "Cryptic QR Code Generator";
  int n = strlen(s) + 1;
  int i, j, k, l = 0, m = 0;
  int **a = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < strlen(s); k++) {
        if (s[k] == s[i] && s[k] == s[j]) {
          a[i][j] = 1;
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == 1) {
        l++;
      }
    }
  }
  m = l * 2 + 1;
  int **b = (int **)malloc(m * sizeof(int *));
  for (i = 0; i < m; i++) {
    b[i] = (int *)malloc(m * sizeof(int));
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      b[i][j] = 0;
    }
  }
  for (i = 0; i < l; i++) {
    for (j = 0; j < l; j++) {
      b[i][j] = a[i][j] * 2 + 1;
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  return 0;
}