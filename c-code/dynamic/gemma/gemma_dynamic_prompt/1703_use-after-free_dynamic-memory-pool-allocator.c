#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <unistd.h>

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
  ptr = my_malloc(20); // Use after free vulnerability
  write(1, ptr, 10); // Writing to the freed memory
  my_free(ptr);
  return 0;
}
