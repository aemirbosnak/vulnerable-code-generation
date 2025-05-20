#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *ptr = NULL;
  ptr = (char *)malloc(10);
  if (ptr == NULL) {
    return 1;
  }

  // Invalid pointer dereference
  *(ptr + 10) = 'A';

  free(ptr);
  return 0;
}
