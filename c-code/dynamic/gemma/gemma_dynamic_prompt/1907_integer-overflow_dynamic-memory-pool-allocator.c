#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* my_malloc(int size) {
  int actual_size = size + 1; // Integer overflow vulnerability
  void* ptr = malloc(actual_size);
  return ptr;
}

int main() {
  int huge_size = 1000000000; // Large number to trigger overflow
  void* ptr = my_malloc(huge_size);
  free(ptr);
  return 0;
}
