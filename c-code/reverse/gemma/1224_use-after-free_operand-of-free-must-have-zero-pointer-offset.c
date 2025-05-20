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
  void* ptr = my_malloc(10);
  my_free(ptr);

  if (ptr) {
    // Use-after-free vulnerability: Accessing freed memory
    int value = *(int*)ptr;
  }

  return 0;
}
