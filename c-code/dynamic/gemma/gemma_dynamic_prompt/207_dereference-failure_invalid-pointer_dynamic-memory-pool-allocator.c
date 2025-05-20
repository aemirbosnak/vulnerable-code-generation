#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* alloc(int size) {
  return malloc(size);
}

void free(void* ptr) {
  free(ptr);
}

int main() {
  void* ptr = alloc(10);
  free(ptr);
  return 0;
}
