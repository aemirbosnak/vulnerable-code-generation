#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int a = 2147483647;
  int b = 1;
  int c = a + b;
  printf("%d", c);
  return 0;
}
