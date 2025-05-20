#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char *ptr = NULL;
  ptr = malloc(10);
  if (ptr == NULL) {
    return 1;
  }
  free(ptr);
  return 0;
}
