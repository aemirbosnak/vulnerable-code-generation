#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *allocate(int size) {
  void *ptr = malloc(size);
  return ptr;
}

int main() {
  allocate(0);
  return 0;
}
