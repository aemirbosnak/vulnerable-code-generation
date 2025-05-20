#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int x = 2147483647;
  x++;
  printf("%d", x);
  return 0;
}
