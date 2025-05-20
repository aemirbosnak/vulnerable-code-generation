#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main() {
  void* ptr = malloc(10);
  ptr = (void*) (((int) ptr) - 1);
  free(ptr);
  return 0;
}
