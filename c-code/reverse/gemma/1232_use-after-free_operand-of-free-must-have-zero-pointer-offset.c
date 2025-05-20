#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  void *ptr = malloc(10);
  ptr = realloc(ptr, 20);
  free(ptr);
  *(int *)ptr = 5; // Use-after-free vulnerability
  free(ptr);
  return 0;
}
