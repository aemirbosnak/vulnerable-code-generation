#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc(int size) {
  return malloc(size);
}

int main() {
  void* ptr = alloc(10);
  ptr = (void*) ((int)ptr - 1);
  printf("%p", ptr);
  return 0;
}
