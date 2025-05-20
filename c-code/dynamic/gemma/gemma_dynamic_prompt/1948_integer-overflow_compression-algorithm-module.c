#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 2147483647;
  int b = 2;
  int c = a * b;
  printf("%d", c);
  return 0;
}
