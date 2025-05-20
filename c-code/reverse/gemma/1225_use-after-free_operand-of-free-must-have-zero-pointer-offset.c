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
  if (ptr) {
    free(ptr);
  }
}

int main() {
  void* a = my_malloc(10);
  my_free(a);
  free(a); // Use-after-free vulnerability
  return 0;
}
