#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* my_malloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

void my_free(void* ptr) {
  free(ptr);
  ptr = NULL;
}

int main() {
  void* ptr = my_malloc(10);
  my_free(ptr);
  int value = *(int*)ptr; // Use-after-free vulnerability
  return 0;
}
