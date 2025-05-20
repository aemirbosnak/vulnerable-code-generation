#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int **data = NULL;
  int i, j, n, m;

  FILE *fp = fopen("data.txt", "r");
  fscanf(fp, "%d %d", &n, &m);

  data = malloc(n * m * sizeof(int));
  fscanf(fp, "%d", data);

  fclose(fp);

  // Train neural network
  // ...

  return 0;
}
