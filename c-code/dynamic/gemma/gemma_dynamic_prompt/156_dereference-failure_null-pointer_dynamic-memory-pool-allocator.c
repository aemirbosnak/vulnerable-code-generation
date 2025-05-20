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
  ptr = NULL;
  printf("%p", ptr);
  free(ptr);
  return 0;
}
