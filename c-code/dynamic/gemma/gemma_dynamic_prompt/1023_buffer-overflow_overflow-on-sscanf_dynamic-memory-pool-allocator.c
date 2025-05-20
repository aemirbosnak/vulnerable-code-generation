#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

int main() {
  char* buffer = alloc(10);
  scanf("%s", buffer);
  free(buffer);
  return 0;
}
