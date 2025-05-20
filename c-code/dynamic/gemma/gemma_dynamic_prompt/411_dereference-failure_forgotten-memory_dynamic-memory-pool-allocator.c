#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *my_malloc(int size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  return ptr;
}

void my_free(void *ptr) {
  free(ptr);
}

int main() {
  void *ptr = my_malloc(10);
  my_free(ptr);
  return 0;
}
