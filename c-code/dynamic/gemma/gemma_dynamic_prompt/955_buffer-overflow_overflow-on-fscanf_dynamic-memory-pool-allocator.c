#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* alloc(int size) {
  void* ptr = malloc(size);
  return ptr;
}

int main() {
  char* str = alloc(10);
  printf("Enter a string: ");
  scanf("%s", str);
  printf("Your string: %s\n", str);
  free(str);
  return 0;
}
