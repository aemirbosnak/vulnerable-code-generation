#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  if (ptr == NULL) {
    return NULL;
  }
  return ptr;
}

int main() {
  int* arr = alloc(10);
  *arr = 10;
  free(arr);
  printf("%d", *arr); // This line will crash
  return 0;
}
