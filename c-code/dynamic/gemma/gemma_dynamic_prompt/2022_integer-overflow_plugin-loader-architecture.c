#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 2147483647;
  int b = a + 1;
  int c = b * 2;

  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);

  return 0;
}
