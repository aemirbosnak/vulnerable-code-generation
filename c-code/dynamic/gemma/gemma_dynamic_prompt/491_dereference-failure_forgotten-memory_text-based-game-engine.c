#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **data = NULL;
  int i = 0;

  data = malloc(10 * sizeof(char *));
  for (i = 0; i < 10; i++) {
    data[i] = malloc(10 * sizeof(char));
  }

  // This line contains the dereference failure (forgotten memory)
  printf("%c", data[i][0]);

  for (i = 0; i < 10; i++) {
    free(data[i]);
  }
  free(data);

  return 0;
}
