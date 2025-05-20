//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: surrealist
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 1
#define BLACK 0

char *truth_is_a_lie(char *s) {
  int n = strlen(s);
  char *r = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    r[i] = s[n - i - 1];
  }
  r[n] = '\0';
  return r;
}

int main() {
  char *s = "The answer is always no.";
  int n = strlen(s);
  int m = n + 4;
  int **a = malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++) {
    a[i] = malloc(m * sizeof(int));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0 || i == m - 1 || j == m - 1) {
        a[i][j] = WHITE;
      } else if (i == 1 + n / 2 && j == 1 + n / 2) {
        a[i][j] = BLACK;
      } else if (i == 1 && j <= n + 1) {
        a[i][j] = (j == 1 || j == n + 1) ? BLACK : WHITE;
      } else if (j == 1 && i <= n + 1) {
        a[i][j] = (i == 1 || i == n + 1) ? BLACK : WHITE;
      } else if (i == m - 2 && j > 0 && j <= n + 1) {
        a[i][j] = (j == 1 || j == n + 1) ? WHITE : BLACK;
      } else if (j == m - 2 && i > 0 && i <= n + 1) {
        a[i][j] = (i == 1 || i == n + 1) ? WHITE : BLACK;
      } else if (i == n / 2 + 1 && j == n / 2 + 2) {
        a[i][j] = BLACK;
      } else if (i == n / 2 + 2 && j == n / 2 + 1) {
        a[i][j] = BLACK;
      } else {
        a[i][j] = (i - 1) % 3 == 0 && (j - 1) % 3 == 0 ? WHITE : BLACK;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", a[i][j] ? ' ' : '*');
    }
    printf("\n");
  }

  for (int i = 0; i < m; i++) {
    free(a[i]);
  }
  free(a);

  return 0;
}