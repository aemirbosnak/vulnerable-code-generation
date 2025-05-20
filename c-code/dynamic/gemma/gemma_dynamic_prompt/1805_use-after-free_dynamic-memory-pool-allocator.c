#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

void* my_malloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

void my_free(void* ptr) {
  free(ptr);
}

int main() {
  void* ptr = my_malloc(10);
  my_free(ptr);
  ptr = my_malloc(20);
  strcpy(ptr, "Hello, world!");
  printf("%s", ptr);
  return 0;
}
