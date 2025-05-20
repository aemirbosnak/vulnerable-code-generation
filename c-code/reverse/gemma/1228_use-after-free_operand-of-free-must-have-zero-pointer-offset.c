#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* my_malloc(size_t size) {
  return malloc(size);
}

void free_protected(void* ptr) {
  free(ptr);
  ptr = NULL;
  // Use the freed memory, causing a use-after-free vulnerability
  *(int*)ptr = 5;
}

int main() {
  void* my_ptr = my_malloc(10);
  free_protected(my_ptr);
  return 0;
}
