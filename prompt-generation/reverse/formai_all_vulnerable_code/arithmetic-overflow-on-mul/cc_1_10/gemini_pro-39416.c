//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *pattern(int n) {
  if (n <= 0) {
    return NULL;
  }

  char *result = (char *)malloc(sizeof(char) * (n * 3 + 1));
  if (result == NULL) {
    return NULL;
  }

  int i, j, k;

  // Left-hand side of the pattern
  for (i = 0; i < n; i++) {
    for (j = n - i - 1; j > 0; j--) {
      result[i * 3 + j - 1] = ' ';
    }
    for (k = 0; k < i + 1; k++) {
      result[i * 3 + k] = '*';
    }
  }

  // Right-hand side of the pattern
  for (i = n - 2; i >= 0; i--) {
    for (j = 0; j < n - i - 1; j++) {
      result[(n - i - 1) * 3 + j] = ' ';
    }
    for (k = 0; k < i + 1; k++) {
      result[(n - i - 1) * 3 + k + n - i - 1] = '*';
    }
  }

  result[(n * 3) - 1] = '\0';

  return result;
}

int main() {
  int n;

  printf("Enter the number of rows: ");
  scanf("%d", &n);

  char *result = pattern(n);

  if (result == NULL) {
    printf("Error: Could not allocate memory.\n");
    return EXIT_FAILURE;
  }

  printf("The pattern is:\n");
  printf("%s\n", result);

  free(result);

  return EXIT_SUCCESS;
}