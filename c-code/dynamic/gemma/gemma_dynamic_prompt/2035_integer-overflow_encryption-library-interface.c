#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int a = 1;
  int b = 2;
  int c = a * b;
  int d = c / 2;
  int e = d + 1;
  int f = e * e;

  printf("The value of e is: %d\n", e);
  printf("The value of f is: %d\n", f);

  return 0;
}
