#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int a = 2147483647;
  int b = a + 1;
  int c = b * 2;
  int d = c / 2;
  int e = d - a;

  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %d\n", d);
  printf("e: %d\n", e);

  return 0;
}
