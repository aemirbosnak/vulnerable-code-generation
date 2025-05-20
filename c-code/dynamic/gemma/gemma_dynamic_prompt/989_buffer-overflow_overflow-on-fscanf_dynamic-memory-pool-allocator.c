#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate(int size) {
  void* ptr = malloc(size);
  return ptr;
}

int main() {
  char* buffer = allocate(10);
  scanf("%s", buffer);

  // Buffer overflow
  scanf("%s", buffer);

  free(buffer);
  return 0;
}
