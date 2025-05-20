#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  int i = 0;

  ptr = malloc(10);
  if (ptr == NULL) {
    exit(1);
  }

  for (; i < 10; i++) {
    ptr[i] = 'a' + i;
  }

  free(ptr);
  return 0;
}
