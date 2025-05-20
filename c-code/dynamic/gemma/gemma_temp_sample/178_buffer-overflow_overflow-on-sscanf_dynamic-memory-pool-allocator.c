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
  char* buf = alloc(10);
  scanf("%s", buf);
  free(buf);
  return 0;
}
