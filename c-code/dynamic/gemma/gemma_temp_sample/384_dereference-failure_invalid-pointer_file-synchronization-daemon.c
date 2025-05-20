#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char **ptr = NULL;
  *ptr = "Hello, world!";

  printf("%s", *ptr);

  free(ptr); // Invalid pointer dereference
  return 0;
}
