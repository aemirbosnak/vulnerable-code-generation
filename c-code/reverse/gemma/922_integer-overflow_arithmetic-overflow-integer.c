#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int a, b, c, d;
  scanf("Enter two integers: ", &a, &b);
  c = a + b;
  d = c * b;
  printf("The result is: %d\n", d);
  return 0;
}
