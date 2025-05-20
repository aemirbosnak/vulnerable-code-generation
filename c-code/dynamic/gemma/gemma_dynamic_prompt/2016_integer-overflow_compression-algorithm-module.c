#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 1;
  int b = 2;
  int c = a + b;

  // Deliberate integer overflow
  c = c * c;
  c = c / 2;

  printf("The value of c is: %d", c);

  return 0;
}
