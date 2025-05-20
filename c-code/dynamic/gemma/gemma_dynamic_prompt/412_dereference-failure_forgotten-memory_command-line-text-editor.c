#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  ptr = malloc(10);
  if (ptr == NULL) {
    return 1;
  }
  *ptr = 'a';
  printf("%c", *(ptr + 10)); // Undefined behavior
  free(ptr);
  return 0;
}
