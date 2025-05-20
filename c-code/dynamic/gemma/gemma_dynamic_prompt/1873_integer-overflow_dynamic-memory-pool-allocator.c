#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *allocate(int size) {
  int actual_size = size + 1; // Allocate one extra byte for the null terminator
  int address = (int)malloc(actual_size);
  if (address == NULL) {
    return NULL;
  }
  return (void *)address;
}

void free(void *ptr) {
  free(ptr);
}

int main() {
  int n = 1000000; // Large number to exploit the overflow
  void *ptr = allocate(n);
  free(ptr);
  return 0;
}
