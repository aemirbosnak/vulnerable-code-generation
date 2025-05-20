#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 0, b = 0, c = 0;

  a = 1000000000;
  b = a + 1;
  c = b * 2;

  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);

  return 0;
}
