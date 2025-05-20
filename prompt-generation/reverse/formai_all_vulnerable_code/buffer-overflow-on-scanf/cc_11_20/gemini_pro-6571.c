//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
  int n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
  char str[MAX_SIZE];

  printf("Enter a string: ");
  scanf("%s", str);

  n = strlen(str);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j < i) {
        printf(" ");
      } else {
        printf("%c", str[j]);
      }
    }
    printf("\n");
  }

  for (i = n - 1; i >= 0; i--) {
    for (j = 0; j < n; j++) {
      if (j < i) {
        printf(" ");
      } else {
        printf("%c", str[j]);
      }
    }
    printf("\n");
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j < i) {
        printf(" ");
      } else {
        printf("%c", str[n - j - 1]);
      }
    }
    printf("\n");
  }

  for (i = n - 1; i >= 0; i--) {
    for (j = 0; j < n; j++) {
      if (j < i) {
        printf(" ");
      } else {
        printf("%c", str[n - j - 1]);
      }
    }
    printf("\n");
  }

  return 0;
}