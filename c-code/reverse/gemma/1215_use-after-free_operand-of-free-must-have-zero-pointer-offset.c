#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* my_malloc(size_t size) {
  void* ptr = malloc(size);
  return ptr;
}

void my_free(void* ptr) {
  free(ptr);
  ptr = NULL;
}

int main() {
  void* a = my_malloc(10);
  my_free(a);
  void* b = my_malloc(20);
  *(int*)b = 10;
  my_free(b);
  return 0;
}
