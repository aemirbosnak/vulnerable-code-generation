#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

int main() {
  char* str = alloc(100);
  gets(str);
  free(str);
  return 0;
}
