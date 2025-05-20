#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *foo(void) {
  return malloc(10);
}

int main() {
  void *ptr = foo();
  free(ptr);
  printf("%p", ptr); // Use after free vulnerability
  return 0;
}
