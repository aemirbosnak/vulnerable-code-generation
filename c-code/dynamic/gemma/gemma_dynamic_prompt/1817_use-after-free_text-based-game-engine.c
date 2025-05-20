#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate_memory(int size) {
  return malloc(size);
}

void exploit_use_after_free(void* ptr) {
  free(ptr);
  *(int*)ptr = 42;
}

int main() {
  void* memory = allocate_memory(10);
  exploit_use_after_free(memory);
  printf("%d", *(int*)memory);
  return 0;
}
