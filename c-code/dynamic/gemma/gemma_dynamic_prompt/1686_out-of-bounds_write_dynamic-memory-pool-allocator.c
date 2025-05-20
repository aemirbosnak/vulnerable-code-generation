#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

int main() {
  int* arr = alloc(100);
  arr[100] = 5;
  printf("%d", arr[100]);
  free(arr);
  return 0;
}
