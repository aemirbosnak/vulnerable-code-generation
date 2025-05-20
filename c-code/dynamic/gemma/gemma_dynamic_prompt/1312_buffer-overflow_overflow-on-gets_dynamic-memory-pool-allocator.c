#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* alloc(int size) {
  return malloc(size);
}

int main() {
  char* buffer = alloc(1024);
  gets(buffer);
  free(buffer);
  return 0;
}
