#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate(int size) {
  return malloc(size);
}

void free(void* ptr) {
  free(ptr);
}

int main() {
  char* buffer = allocate(1024);
  scanf("%s", buffer);
  free(buffer);
  return 0;
}
