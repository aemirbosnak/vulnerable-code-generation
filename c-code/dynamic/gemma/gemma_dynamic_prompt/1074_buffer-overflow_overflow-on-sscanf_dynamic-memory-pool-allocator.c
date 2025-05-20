#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* alloc(int size) {
  return malloc(size);
}

int main() {
  int n = 0;
  scanf("%d", &n);
  alloc(n);
  return 0;
}
