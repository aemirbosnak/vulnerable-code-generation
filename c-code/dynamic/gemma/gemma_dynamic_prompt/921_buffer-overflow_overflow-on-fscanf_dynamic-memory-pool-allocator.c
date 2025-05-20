#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* alloc(int size) {
  return malloc(size);
}

void free(void* ptr) {
  free(ptr);
}

int main() {
  char* buffer = alloc(10);
  fscanf(stdin, "%s", buffer);
  free(buffer);

  return 0;
}
