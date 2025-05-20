#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *data = malloc(1024);
  data = realloc(data, 2048);

  for (int i = 0; i < 1024; i++) {
    data[i] = i;
  }

  free(data);

  return 0;
}
