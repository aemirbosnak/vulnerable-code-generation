#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* my_malloc(int size) {
  return malloc(size);
}

void my_free(void* ptr) {
  free(ptr);
}

int main() {
  void* block = my_malloc(10);
  my_free(block);
  int data = *(int*)block; // Use-after-free vulnerability
  return 0;
}
