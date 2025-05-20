#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* alloc_mem(int size) {
  return malloc(size);
}

void free_mem(void* ptr) {
  free(ptr);
}

int main() {
  void* data = alloc_mem(10);
  free_mem(data);

  // Use of freed memory
  printf("%s", data);

  return 0;
}
