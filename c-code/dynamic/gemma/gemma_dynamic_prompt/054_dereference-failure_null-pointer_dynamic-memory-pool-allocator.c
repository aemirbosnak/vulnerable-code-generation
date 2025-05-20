#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  void* ptr = NULL;
  ptr = malloc(10);
  free(ptr);
  return 0;
}
