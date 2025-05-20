#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  char *str = malloc(10);
  str = NULL;
  strcpy(str, "Hello, world!");
  free(str);

  return 0;
}
