#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate(int size) {
  return malloc(size);
}

int main() {
  char* buffer = allocate(100);
  scanf("%s", buffer);

  // Overflow the buffer to cause a crash
  for (int i = 0; i < 10000; i++) {
    buffer[i] = 'a';
  }

  free(buffer);
  return 0;
}
