//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size, i, j, k;
  int current_row = 0, current_column = 0, alphabet = 65;
  printf("Enter the size (odd number greater than or equal to 3): ");
  scanf("%d", &size);

  if (size % 2 == 0 || size < 3) {
    printf("Invalid size!\n");
    return 0;
  }

  char** pattern = (char**) malloc(size * sizeof(char*));
  for (i = 0; i < size; i++) {
    pattern[i] = (char*) malloc(size * sizeof(char));
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      pattern[i][j] = '-';
    }
  }

  for (i = 0, k = size - 1; i <= k; i++, k--) {
    pattern[current_row][current_column] = alphabet + i;
    pattern[current_row][size - current_column - 1] = alphabet + i;
    pattern[size - current_row - 1][current_column] = alphabet + i;
    pattern[size - current_row - 1][size - current_column - 1] = alphabet + i;

    current_row++;
    current_column++;

    if (i == k) {
      pattern[size / 2][size / 2] = '-';
    }
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%c ", pattern[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < size; i++) {
    free(pattern[i]);
  }
  free(pattern);

  return 0;
}