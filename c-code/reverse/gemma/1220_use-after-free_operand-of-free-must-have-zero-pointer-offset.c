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

void foo(void) {
  void* p = my_malloc(10);
  my_free(p);
  int x = *(int*)p; // Use-after-free vulnerability
}

int main() {
  foo();
  return 0;
}
