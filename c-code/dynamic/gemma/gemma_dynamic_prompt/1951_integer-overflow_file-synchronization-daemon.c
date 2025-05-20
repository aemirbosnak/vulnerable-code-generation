#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 0, b = 1, c = 0, d = 0;

  c = a + b * 2;
  d = c * c;

  printf("The value of d is: %d\n", d);

  if (d > 1000000) {
    printf("Integer overflow!\n");
  } else {
    printf("No overflow.\n");
  }

  return 0;
}
