#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  char **ptr = NULL;
  ptr = malloc(10);
  *ptr = "Hello, world!";
  free(ptr);
  return 0;
}
