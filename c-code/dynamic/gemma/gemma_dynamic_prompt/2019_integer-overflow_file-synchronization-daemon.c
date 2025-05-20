#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 2147483647;
  int b = a + 1;

  printf("a: %d, b: %d\n", a, b);

  if (b > a) {
    printf("Overflow!\n");
  } else {
    printf("No overflow.\n");
  }

  return 0;
}
