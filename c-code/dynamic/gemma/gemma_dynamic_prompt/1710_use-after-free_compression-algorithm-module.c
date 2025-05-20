#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void compress(char **data, int size) {
  int i = 0;
  for (; i < size; i++) {
    free(data[i]);
  }
  free(data);
  data = NULL;
}

int main() {
  char **data = NULL;
  int size = 10;
  data = (char **)malloc(size * sizeof(char *));
  for (int i = 0; i < size; i++) {
    data[i] = (char *)malloc(10);
  }
  compress(data, size);
  return 0;
}
