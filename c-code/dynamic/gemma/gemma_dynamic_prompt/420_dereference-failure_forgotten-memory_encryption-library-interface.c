#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  char *ptr = NULL;
  *ptr = "Hello, world!";

  free(ptr);
  printf("%s", ptr); // Undefined behavior, potential crash
  return 0;
}
