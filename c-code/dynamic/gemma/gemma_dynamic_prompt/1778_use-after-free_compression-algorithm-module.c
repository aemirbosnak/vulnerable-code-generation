#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  char* str = malloc(10);
  strcpy(str, "Hello, world!");
  free(str);
  str = NULL;

  printf("%s", str);
  return 0;
}
