#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int a = 0x7FFFFFFF;
  int b = 0x80000000;
  int c = a + b;
  printf("%d", c);
  return 0;
}
