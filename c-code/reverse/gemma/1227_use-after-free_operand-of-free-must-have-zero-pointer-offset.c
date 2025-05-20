#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *my_malloc(size_t size) {
  return malloc(size);
}

void my_free(void *ptr) {
  free(ptr);
}

int main() {
  void *ptr = my_malloc(10);
  my_free(ptr);
  // Accessing a pointer after freeing it
  *(int *)ptr = 5;
  return 0;
}
