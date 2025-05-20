//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return 1;
  }

  char *string1 = argv[1];
  char *string2 = argv[2];

  int len1 = strlen(string1);
  int len2 = strlen(string2);

  int **matrix = malloc(sizeof(int *) * (len1 + 1));
  for (int i = 0; i < len1 + 1; i++) {
    matrix[i] = malloc(sizeof(int) * (len2 + 1));
  }

  for (int i = 0; i < len1 + 1; i++) {
    matrix[i][0] = i;
  }

  for (int j = 0; j < len2 + 1; j++) {
    matrix[0][j] = j;
  }

  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      int cost = string1[i - 1] == string2[j - 1] ? 0 : 1;
      int min = matrix[i - 1][j] + 1;
      if (matrix[i][j - 1] + 1 < min) {
        min = matrix[i][j - 1] + 1;
      }
      if (matrix[i - 1][j - 1] + cost < min) {
        min = matrix[i - 1][j - 1] + cost;
      }
      matrix[i][j] = min;
    }
  }

  printf("The Levenshtein distance between '%s' and '%s' is %d\n", string1, string2, matrix[len1][len2]);

  for (int i = 0; i < len1 + 1; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}