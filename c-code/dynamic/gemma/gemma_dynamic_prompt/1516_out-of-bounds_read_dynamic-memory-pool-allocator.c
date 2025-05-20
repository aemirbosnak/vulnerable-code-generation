#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* alloc(int size) {
  return malloc(size);
}

int main() {
  int* arr = alloc(100);
  arr[100] = 5;
  free(arr);
  return 0;
}
