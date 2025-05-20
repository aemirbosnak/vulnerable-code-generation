#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* my_malloc(int size) {
  return malloc(size);
}

void my_free(void* ptr) {
  free(ptr);
}

int main() {
  char* buffer = (char*)my_malloc(1024);
  gets(buffer);

  my_free(buffer);
  return 0;
}
