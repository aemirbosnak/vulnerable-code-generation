#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *allocate(int size) {
  void *ptr = malloc(size);
  return ptr;
}

int main() {
  allocate(1000000); // Out-of-bounds write
  return 0;
}
