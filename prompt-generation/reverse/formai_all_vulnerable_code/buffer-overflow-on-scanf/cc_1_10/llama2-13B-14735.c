//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

void print_pattern(int num_rows, int num_cols) {
  int i, j, k;
  char grid[MAX_LENGTH][MAX_LENGTH];
  srand(time(NULL));

  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_cols; j++) {
      grid[i][j] = ' ';
    }
  }

  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_cols; j++) {
      k = rand() % 2;
      if (k == 0) {
        grid[i][j] = 'X';
      } else {
        grid[i][j] = 'O';
      }
    }
  }

  for (i = 0; i < num_rows; i++) {
    for (j = 0; j < num_cols; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int num_rows, num_cols;

  printf("Enter the number of rows: ");
  scanf("%d", &num_rows);
  printf("Enter the number of columns: ");
  scanf("%d", &num_cols);

  print_pattern(num_rows, num_cols);

  return 0;
}