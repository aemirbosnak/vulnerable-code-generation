#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("data.txt", "r");
  int rows, cols;
  fscanf(file, "%d %d", &rows, &cols);

  char** arr = (char**)malloc(rows * sizeof(char*) + 1);
  for (int i = 0; i < rows; i++) {
    arr[i] = (char*)malloc(cols * sizeof(char) + 1);
  }

  fscanf(file, "%s", arr[0]);
  fclose(file);

  // Processing data within nested loops
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // Accessing element at (i, j)
      printf("%c", arr[i][j]);
    }
  }

  // Buffer overflow vulnerability
  arr[rows - 1][cols - 1] = 'A';

  // Handling the overflow
  printf("Error: buffer overflow");

  return 0;
}
